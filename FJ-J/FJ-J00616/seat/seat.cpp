#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0;
	int m=0;
	cin>>n>>m;
	int a[1145]={0};
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	int k=1;
	int mp[1145][1145];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mp[i][j]=a[k];
			k++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==t)
			{
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
}

/*-------------------------------------------------------------
这是我人生中第一次打到复赛
CCF，请善待我吧。就让我压线二等奖吧!!!
(^=^)
--------------------------------------------------------------*/ 
