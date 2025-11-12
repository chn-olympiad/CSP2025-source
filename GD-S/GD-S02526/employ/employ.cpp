#include <bits/stdc++.h>

using namespace std;

const int N=501;
const long long sbccf=998244353;

int n,m;
string s;
int c[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long ans=1;
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	
	bool sp_j=1;
	for(int i=0;i<n;i++)
		if(s[i]!='1')
			sp_j=0;
	
	
	int t=0;
	for(int i=0;i<n;i++)
		cin>>c[i];
	
	for(int i=0;i<n;i++)
	{
		if(c[i]<=t)
			++t;
	}
	
		
//	cout<<t;
	
	if(sp_j)
	{
		for(int i=n-t;i>=2;i--)
		{	
			ans*=i;
			ans%=sbccf;		
		}
		cout<<ans;
	}
		
	
}
