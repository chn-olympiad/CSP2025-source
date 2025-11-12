#include<bits/stdc++.h>
using namespace std;
const int maxn =5e5+10;
int n,k;
int a[maxn]; 
queue<int> q;
int pre=1;
long long ans=0;
long long cnt=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	int g=-1;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
			
		for(int j=1;j<=i;j++)
		{
		if(g==-1)
        {
        	g=a[j];
		}
		else{
			g^=a[j];
		}
		if(g==k)
		{
			g=-1;
			cnt++;
		}
	}
		for(int j=i+1;j<=n;j++)
		{
		if(g==-1)
        {
        	g=a[j];
		}
		else{
			g^=a[j];
		}
		if(g==k)
		{
			g=-1;
			cnt++;
		}
	}
	ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
 } 
