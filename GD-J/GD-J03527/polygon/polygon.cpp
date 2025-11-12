#include<bits/stdc++.h>
using namespace std;
const int N=5e3+8;
int n,ans=0;
int a[N],vis[N];
inline bool check(int m){
	int cnt=0,sum=0,maxn=1;
	for(int i=1;i<=m;i++){
		if(vis[i]){
			cnt++;
			sum+=a[i];
			maxn=max(maxn,a[i]);
			cout<<i<<" ";
		}
	}
	if(cnt!=m||sum<=(maxn*2)){
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 1;
}
inline void dfs(int m,int ind){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(ind==m){
				if(check(m)){
					ans++;
				}
				return ;
			}
			vis[i]=1;
			dfs(m,ind+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,0);
	}
	cout<<ans;
	return 0;
}
