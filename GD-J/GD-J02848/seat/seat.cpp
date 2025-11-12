#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h> 
using namespace std;
int a[1010];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int st;
    for (int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
    	if (i==1)
    	{
    		st=a[i];
		}
	}
	sort(a+1,a+n*m+1);
//	for (int i=n*m;i>=1;i--)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	int cnt;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==st)
		{
			cnt=n*m-i+1;
		}
	}
	//cout<<cnt<<endl;
	int sum=0;
	for (int i=0;i<=m;i++)
	{
		if (cnt>=i*n+1&&cnt<=n+n*i)
		{
			sum=i+1;
		}
	}
	if (sum%2==0)
	{
		cnt-=(sum-1)*n;
		int ans=n-cnt+1;
		cout<<sum<<" "<<ans;
	}
	else
	{
		cnt-=(sum-1)*n;
		cout<<sum<<" "<<cnt;
	}
    return 0;
}
