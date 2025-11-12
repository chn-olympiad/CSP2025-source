#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int dp1[10005][10005]; 
int dp2[10005][10005];
int dp3[10005][10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
		{
			dp1[i][1]=a[i][1];
			dp2[i][1]=a[i][2];
			dp3[i][1]=a[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=n/2;j>0;j--)
			{
				dp1[i][j]=a[i][1]+max(dp1[i-1][j-1],max(dp2[i-1][j],dp3[i-1][j]));     
				dp2[i][j]=a[i][2]+max(dp1[i-1][j],max(dp2[i-1][j-1],dp3[i-1][j]));        
				dp3[i][j]=a[i][3]+max(dp1[i-1][j],max(dp2[i-1][j],dp3[i-1][j-1]));  
			}
		}
		int maxx=-1;
		for(int i=1;i<=n/2;i++)
		{
			int t=max(dp1[n][i],max(dp2[n][i],dp3[n][i]));
			if(t>maxx) maxx=t;
		}
		cout<<maxx<<endl;
	}
	return 0;
 } 
