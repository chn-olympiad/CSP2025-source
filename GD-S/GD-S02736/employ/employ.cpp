#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	long long n, m;
	
	cin>>n>>m;
	
	string s;
	
	cin>>s;
	
	long long a[1007]{};
	long long zhui[1007]{};
	
	for(int i=0;i<n;i++)
	{
		
		cin>>a[i];
		for(int i=0;i<=a[i];i++)
		{
			
			zhui[i]++;
			
		}
		
	} 
	
	/*int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		
		if(s[i]=='1')
		{
			
			cnt++;
			
			if(cnt<)
			
		}
		
	}*/
	
	long long sum=1;
	const long long MOD=998244353;
	
	for(int i=1;i<=n;i++)
	{
		
		sum*=i;
		sum%=MOD;
		
	}
	
	cout<<sum;
	
	return 0; 
	
}
