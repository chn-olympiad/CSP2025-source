#include<bits/stdc++.h>
#define int long long 
const int mod=998244353;
using namespace std;
int n,m,ans;
string s;
int a[200005],vis[200005];
vector<int> e;
void dfs(int sum){
	if(sum==n){
		int f=0,cnt=0,j=0;
		for(auto i:e){
			j++;
//			cout<<i<<" ";
			if(cnt>=a[i]){
				cnt++;
				continue;
			}
			if(s[j]=='0')cnt++;
			else f++;
//			cout<<i<<endl;
		}
//		cout<<endl;
		if(f>=m)ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			e.push_back(i);
			dfs(sum+1);
			vis[i]=0;
			e.pop_back();
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=18){
		dfs(0);
		cout<<ans<<endl;
	}else if(m==n){
		
	}else{
		int f=0;
		for(int i=1;i<=n;i++){
			if(a[i]>0)f++;
		}
		cout<<f<<endl;
		if(f<=m)cout<<0<<endl;
		else{
			int g=1;
			for(int i=1;i<=n;i++){
				g*=i;
				g%=mod;
			}
			cout<<g<<endl;
		}
	}
	
	return 0;
}