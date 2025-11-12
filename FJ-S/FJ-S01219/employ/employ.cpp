#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int a[505];
int c[505];
bool b[505];
const int mod=998244353;
int ans=0;
void dfs(int t,int ans1,int ans2){
	if(n-ans1<m) return;
	if(t==n+1){
		if(ans2>=m){
			ans++;
			ans%=mod;
		}		
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			int p1=ans1,p2=ans2;
			if(ans1>=c[i]) p1++;
			else if(s[t-1]=='0') p1++;
			else p2++;
			b[i]=1;
			dfs(t+1,p1,p2);
			b[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
