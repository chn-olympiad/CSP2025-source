#include<bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
#define ll long long
#define endl "\n"
using namespace std;
int a[1005],ansa;
int x=1,y=1;//行、列 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;//行、列
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ansa=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;)
	{
		for(int j=1;j<=n;j++,i--)//行
		{
			x=j;
			if(a[i]==ansa)
			{
				cout<<y<<' '<<x;
				return 0;
			}
		}
		y++;
		for(int j=n;j>=1;j--,i--)//行
		{
			x=j;
			if(a[i]==ansa)
			{
				cout<<y<<' '<<x;
				return 0;
			}
		}
		y++;
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
