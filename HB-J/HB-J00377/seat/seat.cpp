#include<bits/stdc++.h>
using namespace std;
int x,y,idx,arr[105],mapn[105][105],num;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++)
	{
		cin>>arr[i];
		if(i==1)
		{
			num=arr[i];
		}
	}
	sort(arr+1,arr+1+x*y,cmp);
	for(int i=1;i<=x;i+=2)
	{
		idx=x;
		for(int j=1;j<=2*x;j++)
		{
			if(j<=x)
			{
				mapn[j][i]=arr[(i-1)*2*x+j];
			}
			if(j>x)
			{
				mapn[idx][i+1]=arr[(i-1)*2*x+j];
				idx--;
			}
		}
	}
	if(y%2!=0)
	{
		for(int i=1;i<=x;i++)
		{
			//cout<<(x-1)*y+i<<' ';
			mapn[i][y]=arr[(y-1)*x+i];
		}
	}
	/*for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cout<<mapn[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			if(mapn[i][j]==num)
			{
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
