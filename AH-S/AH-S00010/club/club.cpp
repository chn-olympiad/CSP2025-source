#include<bits/stdc++.h>
using namespace std;
int d[10000][3];
int main()
{
   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;

    for(int i=0;i<t;i++)
    {
		    int ans=0;
		cin>>n;
			 for(int b=0;b<n;b++)
   {
	   cin>>d[b][1]>>d[b][2]>>d[b][3];
	   if(d[b][1]>d[b][2])
{
	d[b][2]=d[b][1];
}
else
{
d[b][1]=d[b][2];
}
if(d[b][1]>d[b][3])
{
	d[b][3]=d[b][1];
}
else
{
d[b][1]=d[b][3];
}
if(d[b][2]>d[b][3])
{
	d[b][3]=d[b][2];
}
else
{
d[b][2]=d[b][3];
}
ans=d[b][1]+ans;
}
cout<<ans;
	}
	return 0;
}

	
