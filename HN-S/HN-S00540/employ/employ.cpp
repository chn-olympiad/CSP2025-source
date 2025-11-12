#include<bits/stdc++.h>
using namespace std;
#define ll long long


int a[1000];
int b[1000];
int n,m;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-b[i-1];
		maxn=max(maxn,a[i]);
	}
		
	sort(a+1,a+n+1);
	
	int num=0;
	int ans=0;
	int x=0;
	
	for(int i=0;i<maxn;i++){
		if(s[i]==1){
			x++;
		}
	}
	
	
	
			
		for(int i=1;i<=n;i++)
		{
			if(b[i]>=s[i-1])
			{
				ans++;
			}
		}
	
		
	
	cout<<ans%998244353;
	
	return 0;
 } 
