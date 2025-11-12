#include<bits/stdc++.h>
using namespace std;
int a[200005][5],b[5],t,s,ans,n,m=-1e9,w;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++) 
			{
				cin>>a[j][k];
			}
		}
		m=-1e9;
		ans=0;
		int b[5]={0,0,0,0,0};
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++) 
			{
				m=max(m,a[j][k]);
				if(m==a[j][k]&&b[k]+1<=n/2) 
				{
					b[k]++;
					b[k--]--;
					w=k;
				}
			}
			if(b[w]<=n/2) ans+=m;
		}
		cout<<ans<<"\n";
	}
	return 0;	
} 
