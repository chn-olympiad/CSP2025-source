#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	int l,r,x,add;
}tr[N*4];
int n,k,a[N],ans,last[N],mem[N];
bool TA=true,TB=true;
void pushup(int k){
	tr[k].x=tr[k*2].x^tr[k*2+1].x;
}
void build(int k,int l,int r){
	tr[k].l=l,tr[k].r=r;
	if(l==r){
		tr[k].x=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid),build(k*2+1,mid+1,r);
	pushup(k);
}
int query(int k,int x,int y){
	int l=tr[k].l,r=tr[k].r;
	if(l>=x&&r<=y){
		return tr[k].x;
	}
	int mid=(l+r)/2,res=0;
	if(x<=mid)res=query(k*2,x,y);
	if(y>mid)res^=query(k*2+1,x,y);
	return res;
}
void dfs(int x,int sum){
	ans=max(ans,sum);
	mem[x]=max(mem[x],sum);
	for(int i=x;i<=n;i++){
		if(last[i]!=-1)dfs(last[i]+1,sum+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),TA=TA&&(a[i]==1),TB=TB&&(a[i]<=1);
	if(TA){
		cout<<n/2;
		return 0;
	}
	if(TB){
		for(int i=1;i<=n;){
			if(k==0){
				if(a[i]==0)ans++;
				else if(a[i]==1&&a[i+1]==1)ans++,i++;
			}else if(k==1&&a[i]==1)ans++;
			i++;
		}
		cout<<ans;
		return 0;
	}
	build(1,1,n);
	memset(last,-1,sizeof(last));
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(query(1,i,j)==k){
				last[i]=j;
				break;
			}
		}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
