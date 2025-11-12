#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10010

ll n,m;
ll mod=998244353;
ll ans=1,k=1;
string s; 
ll t[MAXN],c[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int l=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=l;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
} 
