#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001][4],b[4],ans=-1001;
void go(int i,int m)
{
	if(i==n+1)
	{
		ans=max(ans,m);
	}
	for(int j=1;j<=3;j++)
	{
		if(b[j]<(n/2))
		{
			b[j]++;
			go(i+1,m+a[i][j]);
			b[j]--;
		}
	}
}
int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		ans=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		go(1,0);
		cout<<ans<<endl;
	}
}