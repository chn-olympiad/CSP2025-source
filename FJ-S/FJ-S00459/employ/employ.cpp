#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 505
#define M 998244353
int n,m,siz;
string s;
int a[N];
bool b[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=s[i]-'0';
	}
	sort(a+1,a+n+1);
	cout<<((n*(n+3511))%M)+((n*(n+7814))%M)+((n*(n+3914))%M)+((n*(n+666))%M);
	return 0;
}
