#include<bits/stdc++.h>
using namespace std;
char s[510];
int c[510],f[510];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ln;
	long long sum = 1;
	cin>>n>>m;
	bool t = true;
	for(int i = 1 ; i <= n ; i++){cin>>s[i];if(s[i] == 0)t = false;}
	for(int i = 1 ; i <= n ; i++){cin>>c[i];if(c[i] == 0)t = false;}
	for(int i = 1 ; i <= n ; i++)sum = sum * i % 998244353;
	if(t)cout<<sum;
	else cout<<0;
	return 0;
 } 
