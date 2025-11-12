#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


bool cmp(int a,int b)
{
	if(a>b)
		return true;
	return false;
}
int n,m,r,sum=0;
int grade[102];
int main()
{
	freopen("seat.in","r",stdin);    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		scanf("%d",&grade[i]);
	r=grade[1];
	sort(grade+1,grade+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		sum++;
		if(grade[i]==r)
			break;
	}
	int tmp=0,a;
	bool tf=false;
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				tmp++;
				if(tmp==sum)
				{
					a=j;
					tf=true;
					break;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				tmp++;
				if(tmp==sum)
				{
					a=j;
					tf=true;
					break;
				}
			}
		}
		if(tf==true)
		{
			cout<<i<<' '<<a;
			break;
		}
	}
	return 0;
}
