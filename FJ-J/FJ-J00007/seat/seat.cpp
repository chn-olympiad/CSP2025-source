/*
T2 sb题，我很好奇为什么数据范围给的这么小，这题不是能读进去就能做吗？？？直接模拟即可，没有难度 
9:52过了ABC 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N];
int mp[200][200];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt1=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				mp[i][j]=a[++cnt1];
				//cout<<cnt1<<" ";
				if(mp[i][j]==cnt)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				mp[i][j]=a[++cnt1];
				//cout<<cnt1<<" ";
				if(mp[i][j]==cnt)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
} 
