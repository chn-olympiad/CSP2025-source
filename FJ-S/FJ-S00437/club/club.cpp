#include<bits/stdc++.h>
using namespace std;
int t,n,sum,a[100001][4],ans;
int main()
{
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	cin>>t>>n;
	for(int p = 1;p<=t;p++)
	{
		for(int i =1;i<=n;i++)
		{
			for (int j =1;j<=i;j++)
			{
				cin>> a[i][j];
			}
		}
	}
	for(int p =1;p<=t;p++)
	{
		ans = 0;
		sum = 0;
		for(int i = 1;i<=n;i++)
		{
			for(int j =1;j<=3;j++)
			{
				if(a[i][j+1] > a[i][j])
					ans = a[i][j+1];
					sum+= ans;
					break;
				if(a[i][j+1] < a[i][j])
					ans = a[i][j];
					sum += ans;
					break;
				if(a[i][j+1] = a[i][j])
					ans = a[i][j];
					sum += ans;
					break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}                