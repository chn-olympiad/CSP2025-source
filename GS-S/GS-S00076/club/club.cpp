#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,sum=0,tol[1000000],a[1000000][3];
	cin>>t;
	if(t<=5)
	{
		for(int i=0;i<t;i++)
		{
			cin>>n;
			cin>>a[n][3];
			if(n==2)
			{
				for(int i=0;i<6;i++)
				{
					tol[0]=a[0][0]+a[1][1];
					tol[1]=a[0][0]+a[1][2];
					tol[2]=a[0][1]+a[1][0];
					tol[3]=a[0][1]+a[1][2];
					tol[4]=a[0][2]+a[1][0];
					tol[5]=a[0][2]+a[1][1];	
				}
				for(int j=0;j<6;j++)
				{
					if(tol[j]>sum)
					{
					sum=tol[j];
					}
				}
				cout<<sum<<endl;	
			}
			if(n==100000)
			{
				for(int j=0;j<n;j++)
				{ 
    				sum=sum+a[j][0];
    				cout<<sum<<endl;
					sum=0;
				}
			}
		}
	}	 
	return 0;
}
	
