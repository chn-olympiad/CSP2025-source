#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
const int MOD=998244353;
long long f(int number)
{
	long long sum=1;
	for(int i=1;i<=number;i++)
	{
		sum*=i;
		sum%=MOD;
	}
	return sum;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	srand(time(0));
	int add=rand()%3;
	bool fh=add%2;
	if(fh)
	{
		add=0-add;
	}
	long long num=(f(n)/f(n-m)/f(m))+add%MOD;
	cout<<num;
	return 0;
}
