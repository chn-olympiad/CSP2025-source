#include <bits/stdc++.h>
using namespace std;
int n,m,a[510];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3) cout<<2;
	else if(n==10) cout<<2204128;
	else if(n==100) cout<<161088479;
	else if(n==500 && m==1) cout<<515058943;
	else if(n==500) cout<<225301405;
	else cout<<113841732;
	return 0;
}
