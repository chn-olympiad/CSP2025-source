#include<bits/stdc++.h>
using namespace std;
struct node
{
	int gra,num;
}input[105];
bool cmp(node a,node b)
{
	if(a.gra>b.gra)
	    return 1;
	return 0;
}
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    cin>>input[i].gra,input[i].num=i;
	sort(input+1,input+1+n*m,cmp);
	int now=0;
	if(m%2)
	{
		for(int i=1;i<=m/2;i++)
		{
			int j=1;
			for(;j<=n;j++)
			    if(input[++now].num==1)
			    {
			    	cout<<i*2-1<<" "<<j;
			    	return 0;
				}
			j=n;
			for(;j;j--)
			    if(input[++now].num==1)
			    {
			    	cout<<i*2<<" "<<j;
			    	return 0;
				}
		}
		int j=1;
		for(;j<=n;j++)
			if(input[++now].num==1)
			{
			    cout<<m<<" "<<j;
			    return 0;
			}
	}
	else
	{
		for(int i=1;i<=m/2;i++)
		{
			int j=1;
			for(;j<=n;j++)
			    if(input[++now].num==1)
			    {
			    	cout<<i*2-1<<" "<<j;
			    	return 0;
				}
			j=n;
			for(;j;j--)
			    if(input[++now].num==1)
			    {
			    	cout<<i*2<<" "<<j;
			    	return 0;
				}
		}
	}
}