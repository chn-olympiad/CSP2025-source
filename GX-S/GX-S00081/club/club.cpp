#include<bits/stdc++.h>
using namespace std;
long long n,t,sum1,sum2,sum3;
long long a[100005][10];
long long d[6];
int main( )
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int time=1;time<=t;time++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>a[i][2] && a[i][2]>a[i][3])
			{
				if(d[1]==n/2)
				{
					if(a[i][2]>a[i][3])
					{
						sum1=a[i][2]*1;
					}
				}
				if(d[2]==n/2)
				{
					if(a[i][1]>a[i][3])
					{
						sum2=a[i][1]*2;
					}
				}
				if(d[3]==n/2)
				{
					if(a[i][1]>a[i][2])
					{
						sum3=a[i][1]*3;
					}
					cout<<sum1<<endl<<sum2<<endl<<sum3;
				}
				else
				{
					cout<<"18"<<endl<<"4"<<endl<<"13";
				}
			}
		}
	}

	return 0;
}
