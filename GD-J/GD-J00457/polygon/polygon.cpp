#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans,num,x,f[5001];
bool vis[5001];
bool check(){
	int maxn=-1000,sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			maxn=max(maxn,a[i]);
			sum+=a[i];
			
		}
	}
	return sum>2*maxn;
}
bool check2(int l,int r){
	int maxn=-1000,sum=0;
	for(int i=l;i<=r;i++){
		if(1==1){
			maxn=max(maxn,a[i]);
			sum+=a[i];
			
		}
	}
	return sum>2*maxn;
}
void dfs(int l,int r){
	x++;
	if(num>=3){
			if(check()){
				ans++;
				return;
			}
	}
	for(int i=l;i<=r;i++){
		if(!vis[i]&&num<3){
			vis[i]=1;
			num++;
			dfs(l,r);
			vis[i]=0;
			num--;
		}
	}
}
int main(){
	freopen("polygon3.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[3]=check2(1,3);
	for(int i=4;i<=n;i++){
		dfs(1,i);
		f[i]=f[i-1]+ans;
	}
	ans=0;
	dfs(1,n);
	cout<<ans/2%988%244%353;
	return 0;
}
