#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[1000],sum,zw[15][15],num;
bool cmp(long long x,long long y)
{
	if(x>y) return true;
	else {
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sum++;
			cin>>a[sum];
		}
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	sum=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1) 
		{
			for(int i=1;i<=n;i++)
			{
				sum++;
//				zw[i][j]=a[sum];
				if(a[sum]==num)
				{				
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--)
			{
				sum++;
//				zw[i][j]=a[sum];
				if(a[sum]==num)
				{	
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<zw[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
} 
// 3 3 94 95 96 97 98 99 100 93 92
