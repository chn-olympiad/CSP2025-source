#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],c[N];
struct node{
	int l,r,cost;
}e[N];
bool cmp(node x,node y){
	if(x.cost==y.cost)return x.r>y.r;
	return x.cost<y.cost;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,p=0,ans=0,num=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		if(a[i]==1)num++;
	}
	if(k<=1){
		if(k==0)printf("%d",num/2);
		else printf("%d",num);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=b[i-1]^b[j];
			if(cnt!=k)continue;
			p++;
			e[p].l=i,e[p].r=j,e[p].cost=j-i+1;
		}
	}
	sort(e+1,e+1+p,cmp);
	for(int i=1;i<=p;i++){
		bool flag=0;
		for(int j=e[i].l;j<=e[i].r;j++){
			if(c[j]==1){
				flag=1;
				break;
			}
		}
		if(flag)continue;
		ans++;
		for(int j=e[i].l;j<=e[i].r;j++){
			c[j]=1;
		}
	}
	printf("%d",ans);
	return 0;
}
