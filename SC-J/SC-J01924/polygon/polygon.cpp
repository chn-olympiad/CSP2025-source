#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt,p[5010][4],pa[5001],h,pan[5001];
bool vis[5010],f;
void dfs(int l,int max1,int b){
	if(b>=3&&l>max1*2){
		for(int i=1;i<=n;i++){
			if(vis[i]) h+=i;
		}
		for(int i=1;i<=cnt;i++){
			if(p[i][1]==l&&p[i][2]==max1&&p[i][3]==b&&pa[i]==h) f=1;
			if(pa[i]==h&&p[i][3]==b) f=1;
		}
		if(!f){
			cnt++;
			cnt=cnt%998244353;
			p[cnt][1]=l;
			p[cnt][2]=max1;
			p[cnt][3]=b;
			pa[cnt]=h;
		}
		h=0;
		f=0;
	}
	if(b==n) return;
	for(int i=1;i<=n;i++){
		if(b==0){
			vis[i]=1;
			dfs(l+a[i],max(max1,a[i]),b+1);
		}
		if(!vis[i]){
			vis[i]=1;
			dfs(l+a[i],max(max1,a[i]),b+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}