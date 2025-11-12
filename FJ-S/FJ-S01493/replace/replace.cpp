#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005],c,d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	
	while(q--)
	{
		cin>>c>>d;
		int x=c.size(),y=d.size();
		if(x!=y)
		{
			cout<<0<<endl;
		}
		
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				int l=c.find(a[i]);
				int r=d.find(b[i]);
				if(l==r&&l!=-1)
				{
					bool ff=0;
					for(int j=0;j<=l;j++)
					{
						if(c[j]!=d[j])
						{
							ff=1;
						}
						
					}
					
					for(int j=n-1;j>l;j--)
					{
						if(c[j]!=d[j])
						{
							ff=1;
						}
						
					}
					
					if(ff==0)
					{
						ans++;
					}
					
				}
				
			}
			
			
			cout<<ans<<endl;
		}
		
	}
	
	return 0;
}
