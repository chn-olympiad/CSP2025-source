#include <bits/stdc++.h>
#define ll long long
#define Mod 998244353
using namespace std;

const int N=505;
int n,m;
int c[N],C[N];
char s[N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
		if (s[i]=='0') f=false;
	}
	for (int i=1;i<=n;i++) {
		cin>>c[i];
		C[i]=c[i];
	}
	if (f) {
		int ans=1;
		for (int i=1;i<=n;i++) 
			ans=(ans*i)%Mod;
		cout<<ans;
	}
	return 0;
}
