#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
int n,m;
string s;
const int N=510;
int c[N];
bool f[12];
int a[12],ans;
void dfs(int step){
	if(step>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=c[a[i]]) cnt++;
		}
		if(n-cnt>=m) ans++;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!f[i]){
				f[i]=true;
				a[step]=i;
				dfs(step+1);
				a[step]=0;
				f[i]=false;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s='#'+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else{
		bool f1=true,f2=true;
		for(int i=1;i<=n;i++) f1&=s[i]=='1';
		for(int i=1;i<=n;i++) f2&=c[i]>=1;
		if(f1&&f2){
			int ans=1;
			for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
			cout<<ans;
		}
		else cout<<0;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
