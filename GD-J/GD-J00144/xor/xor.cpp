#include<bits/stdc++.h>
using namespace std;
long long a[600005],b,c,d,g[600005],k,q;
map <long long,int> w;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	q=1;
	cin>>b>>c;
	for(int i=1;i<=b;i++)
	{
		cin>>a[i]; 
		if(g[i-1])
		{
			g[i]=a[i]^g[i-1];
		}
		else
		{
			g[i]=a[i];
		}
		if((w[(g[i]^c)]==1)||((g[i]^c)==0))
		{
			int o=g[i]^c;
			
			k+=1;
			for(int j=i;j>=q;j--)
			{
				w[g[j]]=0;
			}
			q=i+1;
			g[i]=0;
		}
		else
		w[g[i]]=1;
	}
cout<<k;
	return 0;
 } 
