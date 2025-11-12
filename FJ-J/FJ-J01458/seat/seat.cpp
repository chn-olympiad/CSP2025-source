#include <bits/stdc++.h>
using namespace std;

struct node{
	long long s;
	bool id;
}b[250];
bool cmp(node x,node y)
{
	return x.s>y.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	b[1].id=1;
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>b[i].s;
	}
	sort(b+1,b+n*m+1,cmp);
	long long cnt=0;
	for(long long i=1;i<=m;i++)
	{
		
	    if(i%2==1)
	    {
	    	for(long long j=1;j<=n;j++)
	    	{
	    		cnt++;
	    		
	    		if(b[cnt].id==1)
	    		{
	    			cout<<i<<" "<<j;
	    			return 0;
				}
			}
		}
		else
	    {
	    	for(long long j=n;j>=1;j--)
	    	{
	    		cnt++;
	    		if(b[cnt].id==1)
	    		{
	    			cout<<i<<" "<<j;
	    			return 0;
				}
			}
		}
	}
	
	return 0;
 } 
