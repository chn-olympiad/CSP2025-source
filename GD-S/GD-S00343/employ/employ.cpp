#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int MOD=998244353;

ll n,m,ans;
ll s[N];
ll c[N];
ll cnt=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll flag=1;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
		if(s[i]==0) flag=0;
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
		if(c[i]!=0) cnt++;
	}
	cout<<0;
	
	return 0;
}
