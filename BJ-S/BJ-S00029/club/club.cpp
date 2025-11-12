#include<bits/stdc++.h>
using namespace std;
int n;
int d[100][4];
int f(int l,int a,int b,int c,int ans)
{
	if(l==n)
	{
		return 0;
	}
	int ans1=0,ans2=0,ans3=0;
	if(a>0)
	{
		ans1=f(l+1,a-1,b,c,ans)+d[l][0];
	}
	if(b>0)
	{
		ans2=f(l+1,a,b-1,c,ans)+d[l][1];
	}
	if(c>0)
	{
		ans3=f(l+1,a,b,c-1,ans)+d[l][2];
	}
	return max(ans,max(ans1,max(ans2,ans3)));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>d[i][0]>>d[i][1]>>d[i][2];
		}
		cout<<f(0,n/2,n/2,n/2,0)<<"\n";
	}
	return 0;
}
