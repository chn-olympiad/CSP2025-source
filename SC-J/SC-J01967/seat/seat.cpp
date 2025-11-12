#include <bits/stdc++.h>
using namespace std;

const int N=20;
int a[N];
int num[N][N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int jilu=0;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	jilu=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	bool flag=0;
	int cur=0;
	while(x>=1&&x<=n&&y>=1&&y<=n)
	{
//		cout<<"x="<<x<<" y="<<y<<endl;
//		cout<<cur+1<<endl;
		num[x][y]=a[++cur];
		if(x==n&&flag==0) y++,flag=1;
		else if(x==1&&flag==1) y++,flag=0;
		else if(flag==0) x++;
		else if(flag==1) x--;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++) cout<<num[i][j]<<" ";
//			cout<<endl;
//		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(num[i][j]==jilu)
			{
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}