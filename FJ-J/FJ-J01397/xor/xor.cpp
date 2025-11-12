#include<bits/stdc++.h>
using namespace std;
int ejzs[8]={1,2,4,8,16,32,64,128};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int kd[8];
	int num3=0;
	for(int j=0;j<8;j++)
	{
		if(k==1)
		{
			kd[j]=1;
			num3++;
			break;
		}
		kd[j]=k%2;
		k/=2;
		num3++;
	}
	if(num3!=7)
	{
		for(int j=num3;j<8;j++)
		{
			kd[j]=0;
		}
	}
	int a[n];
	int b[n][9];
	int maxnum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i][0]=a[i];
		int num=0;
		for(int j=1;j<9;j++)
		{
			if(b[i][0]==1){
				b[i][j]=1;
				num++;
				break;
			}
			b[i][j]=b[i][0]%2;
			b[i][0]/=2;
			num++;
		}
	}
	int num=0;
	for(int i=0;i<n;i++)
	{
		int num2[8];
		int sum=0;
		for(int j=i;j<n;j++)
		{
			for(int x=i;x<j;x++)
			{
				for(int y=1;y<9;y++)
				{
					if(b[x][y]!=b[x+1][y])
					{
						num2[sum]=1;
						sum++;
					}
				}
			}
		}
		if(sum!=7)
		{
			for(int j=sum;j<8;j++)
			{
				num2[j]=0;
			}
		}
		bool sun=true;
		for(int y=0;y<8;y++)
		{
			if(num2[y]!=kd[y])
			{
				sun=false;
			}
		}
		if(sun)
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
