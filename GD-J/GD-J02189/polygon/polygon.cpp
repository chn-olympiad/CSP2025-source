#include<bits/stdc++.h>
using namespace std;
int n,a[7005],dp1[5005][5005],dp2[5005];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dp1[1][a[1]]++;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=5001;j++)
		{
			dp1[i][j]=dp1[i-1][j]+dp1[i-1][j+a[i]];
		}
		cout<<dp1[i][a[1]-a[i]]<<" ";
		dp1[i][a[i]]++;
		int sum=0;
		for(int j=1;j<a[i];j++)
		{
			
			sum+=dp1[i-1][j];
		}
		for(int j=1;j<=10;j++) cout<<dp1[i][j]<<" ";
		cout<<endl;
		dp2[i]=dp2[i-1]+sum;
	}
	cout<<dp2[n];
	
	return 0;
}
