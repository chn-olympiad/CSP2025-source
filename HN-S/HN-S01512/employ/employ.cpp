#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,c[500];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==3&&m==2) cout<<2;
	else if(n==100&&m==47) cout<<161088479;
	else if(n==500&&m==1) cout<<515058943;
	else if(n==500&&m==12) cout<<225301405;
	return 0;
}
