#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int mod=998244353;
int n;
int a[5010];
map<int,int>mp;
int st[5010];
vector<int>v;
int o=1;
int ans=0;
void dfs(int len,int cnt,int k){
	if(cnt==len){
		int sum=0;
		int mx=-INF;
		for(auto i:v){
			sum+=i;
			mx=max(mx,i);
		}
		if(sum<=mx*2) return ;
		ans++;
		ans%mod;
		return ;
	}
	for(int i=k;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			v.push_back(a[i]);
			cnt++;
			dfs(len,cnt,i+1);
			cnt--;
			v.pop_back();
			st[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int xx=n+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(xx>=3){
		memset(st,0,sizeof st);
		for(auto j:v){
			j=0;
		} 
		dfs(xx,1,1);
		xx--;
	}
	cout<<ans%mod;
	return 0;
} 
