#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[20][20],ii=1,nn=1,mm=0,sum=0,seat = 0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		//cout<<"a[i]="<<a[i]<<endl;
	}
	int num = a[1];
	//cout<<"num="<<num<<endl;
	sort(a,a+n*m+1);
	/*for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<" ";
	}*/
	//cout<<endl;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i] == num)
		{
			sum = n*m-i+1;                //sum为标号,sum-1为下标
			//cout<<"21i="<<i<<endl;     //名次 
			break;
		}
	}
	//cout<<"sum="<<sum<<endl;
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j] = a[ii];
			ii++;
			if(b[i][j] == num)
			{
				nn = i;
				mm = j;
				cout<<"i j"<<i<<" "<<j<<endl;
				break;
			}
		}
	}*/
	
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				//坐标 i j
				seat++;
				if(seat == sum)
				{
					cout<<i<<" "<<j;
				}
			}
		}
		else
		{
			for(int j=m;j>0;j--)
			{
				//坐标 i j 
				seat++;
				if(seat == sum)
				{
					cout<<j<<" "<<i;
				}
			}
		}
	}
	//out<<mm<<" "<<nn;
	return 0;
}
