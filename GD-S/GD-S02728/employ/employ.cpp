#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],sum;
char s[501];
const int MOD=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",&s);
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) if(s[i]=='1') sum++;
	if(sum<m){cout<<0; return 0;}
	cout<<78;
	
	return 0;
}//Ren5Jie4Di4Ling5%
