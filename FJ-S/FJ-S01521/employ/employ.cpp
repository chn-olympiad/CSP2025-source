#include<bits/stdc++.h>
using namespace std;
int n,m,c[501];
long long ans=0;
string s;
void emp(int day,int pass)
{
	if(pass>=m)
	{
		ans++;
		ans%=998244353;
	}
	for(int i=0;i<n;i++)
	{
		if(day-pass-1>=c[i]) continue;
		int x=c[i];
		c[i]=-4;
		emp(day+1,pass+s[day-1]-'0');
		c[i]=x;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	emp(1,0);
	cout<<ans;
	return 0;
}
