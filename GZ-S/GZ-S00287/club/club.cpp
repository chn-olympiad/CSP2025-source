//GZ-S00287 毕节东辰实验学校 武运隆
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int sum;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int floor=3*n;
	while(t--)
	{
		cin>>n;
		int floor=3*n;
		for(int i=0;i<floor;i++)
		{
			cin>>a[i];
		}

		for(int j=0;j<floor;j++)
		{
			for(int i=0;i<floor;i++)
			{
				int m,n;
				m=a[i];
				n=a[i+1];
				if(m<n)
				{
					a[i]=n;
					a[i+1]=m;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			sum+=a[i];
		}
	}
	cout<<sum;
	return 0;
}
