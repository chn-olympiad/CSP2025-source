#include <bits/stdc++.h>
#define MOD 998244353 
using namespace std;

int n,m;
int a[505];
string s;
bool pd()
{
	for(int i=0; i<n; i++)
	{
		if(s[i] == '0')
			return false;
	}
	
	return true;
}

long long mi(int k)
{
	long long sum=1;
	for(int i=1; i<=k; i++)
		sum=(sum*i)%MOD;
		
	return sum;
}

int f()
{
	int i,ans=0;
	long long sum=1;
	for(i=1; i<=n; i++)
	{
		if(s[i] == '1')
			break;
	}
	
	for(int j=1; j<=n; j++)
	{
		if(a[j] >= i)
			ans++;
	}	
	
	for(int j=1; j<i; j++)
		sum=(sum*(n-i+1))%MOD;
		
	sum*=ans%MOD;
	return sum;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++)
		cin>>a[i];	
	
	if(m == 1)
		cout<<f()%MOD;
	else if(m == n || pd())
		cout<<mi(m)%MOD;
	
	return 0;
}
