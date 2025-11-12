#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n;
int arr[maxn];
bool vis[maxn];
long long ans=0;
set<int>s;
void dfs(int y,int dis){
	if(y>n)return ;
	int sum=0,maxn=0;
	if(dis>=3){
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=arr[i];
				maxn=max(maxn,arr[i]);
			}
		}
		if(s.find(sum)!=s.end())goto flag;
		else s.insert(sum);
		if(sum>maxn*2){
			ans++;
//			for(int i=1;i<=n;i++)if(vis[i])cout<<arr[i]<<" ";
//			cout<<"\n";
//			cout<<sum<<" "<<maxn<<"\n";
		}
	}
	for(int i=y+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,dis+1);
			vis[i]=0;
			dfs(i,dis);
		}
	}
	flag:
	for(int i=y+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,dis+1);
			vis[i]=0;
			dfs(i,dis);
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	vis[1]=1;
	dfs(1,1);
	cout<<ans%998244353<<"\n";
	return 0;
}
