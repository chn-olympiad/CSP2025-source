#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m,c[N],a[N],ans;
string s;
bool vis[N];
void fun(int x,int k){
	if(x==n){
		if(k==n){
			int x=0;
			int q=s.size();
			for(int i=0;i<q;i++){
				if(s[i]=='1'&&x<c[a[i]])ans++;
				if(s[i]=='0')x++;
				ans%=mod;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;a[k+1]=i;
		fun(x+1,k+1);
		vis[i]=0;
		fun(x+1,k);
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	fun(0,0);
	cout<<ans%mod<<'\n';
	return 0; 
}
