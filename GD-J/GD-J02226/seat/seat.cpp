#include<bits/stdc++.h>
using namespace std;
int fm[110][110],n,m,a[10010],r_f;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int all_r=n*m;
	for(int i=1;i<=all_r;i++) cin>>a[i];
	r_f=a[1];
	sort(a+1,a+all_r+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=all_r;i++)
	{
		
		fm[x][y]=a[i];
		if(a[i]==r_f)
		{
			cout<<y<<' '<<x;
//			return 0;
			break;
		}
		
		if(y%2==0)
		{
			if(x<=1)
			{
				y++;
//				continue;
			}
			else
			{
				x--;
//				continue;
			}
		}
		else
		{
			if(x>=n)
			{
				y++;
//				continue;
			}
			else
			{
				x++;
//				continue;
			}
		}
		
		
	}
	
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			printf("%4d",fm[i][j]);
//		}
//		cout<<endl;
//	}
	return 0;
}
