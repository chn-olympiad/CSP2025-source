#include<bits/stdc++.h>
using namespace std;
int n,a[10086];
bool vis[10086];
bool check(int sum,int maxnum){
	return sum>2*maxnum;
}
int ans=0;
void dfs(int k,int id,int sum,int maxnum,int len){
	if(k>len&&check(sum,maxnum)){
		ans++;
		return;
	}
	else if(k>len)return;
	for(int i=id+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,i,sum+a[i],max(maxnum,a[i]),len);
			vis[i]=0;
		}
	}
}
int cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,0,0,0,i);
		cnt+=ans;
		ans=0;
	}cout<<cnt%998244353;
	return 0;
} 
