#include<bits/stdc++.h>
using namespace std;
int xo(int x,int y){
	int a[22]={},b[22]={},c[21];
	int ans=0;
	int cnt1=0,cnt2=0;
	if(x==0) return y;
	if(y==0) return x;
	if(x==y) return 0;
	while(x!=0){
		a[++cnt1]=x%2;
		x=x/2;
	}
	while(y!=0){
		b[++cnt2]=y%2;
		y=y/2;
	}
	for(int i=1;i<=max(cnt1,cnt2);i++){
		c[i]=(a[i]+b[i])%2;
	}
	for(int i=max(cnt1,cnt2);i>=1;i--){
		ans=(ans+c[i])*2;
	}
	return ans/2;
}
struct node{
	int l,r;
}ans[500001];
bool cmp(node x,node y){
	if(x.r-x.l!=y.r-y.l) return x.r-x.l<y.r-y.l;
	else return x.l<y.l;
}
int a[500001],cnt=0,b=0,f[500001],auv1,auvmax;
bool vis[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	f[i]=1;
	}
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=i;j<=n;j++){
			tmp=xo(tmp,a[j]);
			if(k==tmp){
				ans[++cnt].l=i;
				ans[cnt].r=j;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		auv1=1;
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		for(int j=ans[i].l;j<=ans[i].r;j++){
			vis[j]=1;
		}
		for(int j=1;j<=cnt;j++){
			if(vis[ans[j].l]||vis[ans[j].r]) continue;
			auv1++;
			for(int u=ans[j].l+1;u<ans[j].r;u++){
				if(vis[u]){
					auv1--;
					break;
				}
			}
		}
		auvmax=max(auv1,auvmax);
	}
	cout<<auvmax;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

