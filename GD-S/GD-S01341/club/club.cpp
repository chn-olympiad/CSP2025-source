#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int t;
int n;
int a1[maxn],a2[maxn],a3[maxn];
int a[4];
struct ed
{
	int maxx,s;
	int maxx2,s2;
}e[maxn];
bool cmp(ed x,ed y)
{
	return x.maxx>y.maxx; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++)
    {
    	memset(a,0,sizeof(a));
    	cin>>n; 
    	for(int i=1;i<=n;i++)
    	{
    		cin>>a1[i]>>a2[i]>>a3[i];
            e[i].maxx=max(a1[i],max(a2[i],a3[i]));
            if(e[i].maxx==a1[i])
            {
            	e[i].s=1;
            	e[i].maxx2=max(a2[i],a3[i]);
            	if(e[i].maxx2==a2[i])
            	{
            		e[i].s2=2;
				}
				else
				{
					e[i].s2=3;
				}
			}
			else if(e[i].maxx==a2[i])
			{
				e[i].s=2; 
            	e[i].maxx2=max(a1[i],a3[i]);
            	if(e[i].maxx2==a1[i])
            	{
            		e[i].s2=1;
				}
				else
				{
					e[i].s2=3;
				}
			}
			else
			{
				e[i].s=3;
            	e[i].maxx2=max(a1[i],a2[i]);
            	if(e[i].maxx2==a1[i])
            	{
            		e[i].s2=1;
				}
				else
				{
					e[i].s2=2;
				}
			}
		}
		sort(e+1,e+n+1,cmp);
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
		    if(a[e[i].s]<n/2)
		    {
		    	a[e[i].s]++;
		    	sum+=e[i].maxx;
			}
			else
			{
				a[e[i].s2]++;
				sum+=e[i].maxx2;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
