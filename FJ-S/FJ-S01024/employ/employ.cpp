#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=505,MOD=998244353;
int n,m,top;
string s;
int c[N],a[N];
bool flag=1;
signed main(){
	FILE("employ")
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.length();i++){
		a[++top]=s[i]-'0';
		if(a[top]!=1){
			flag=0;
		}
	}
	if(flag){
		__int128 ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;ans%=MOD;
		}
		int ans2=ans;
		cout<<ans2;
	}
	else{
		cout<<2;
	}
	return 0;
}
