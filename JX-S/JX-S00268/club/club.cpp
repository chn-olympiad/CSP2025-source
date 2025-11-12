#include<bits/stdc++.h>
using namespace std;
int main()
{
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
int a,s,dd=0;
cin>>a;
for(int i=0;i<a;i++)
{
	cin>>s;
	dd=0;
	int q=0,w=0,e=0;
	for(int j=0;j<s;j++)
	{
		int d,f,g;
		cin>>d>>f>>g;
		int ii;
		ii=max(max(d,f),g);
		if (ii==d&&q>=s/2)
				{
			if (f==max(f,g))
			{
				if (w>a/2)
				{
					e++;
					ii=g;
				}
				else
				{
				 w++;
				 ii=f;
			 }
			}
			else 
			{
			q++;
			ii=d;
			}
				}
		
		else if (ii==f&&w>=s/2)
			{
			if (d==max(d,g))
			{
				if (w>a/2)
				{
					e++;
					ii=g;
				}
				else 
				{
			ii=d;
				q++;
			}
			}
			
			else 
			{
			w++;
		ii=f;
			}
		}
		
			else if (ii==g&&e>=s/2)
						{
			if (f==max(d,f))
					{
				if (w>a/2)
						{
					q++;
					ii=d;
						}
				else 
				{
				e++;
			ii=w;
				}
					}
			else 
			{
			ii=e;
			w++;
		}
		cout<<q<<" ";
		}
		dd=dd+ii;
		
		
		}
		cout<<dd<<endl;
	}
	
	
	

return 0;
}
