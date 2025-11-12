#include<bits/stdc++.h>
using namespace std;
int a[105];
int p=0;
int t=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[t]==p)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				t++;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(a[t]==p)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				t++;
			}
		}
		
	}
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
*/
