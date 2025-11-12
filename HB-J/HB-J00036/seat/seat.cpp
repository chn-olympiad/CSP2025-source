#include<bits/stdc++.h>
using namespace std;
int num[11][11],grade[105],n,m,stu,wei=1,a1,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&m,&n);
	stu=n*m;
	for(int i=1;i<=stu;i++)
	{
		scanf("%d",&grade[i]);
	}
	a1=grade[1];
	for(int i=1;i<=stu;i++)
	{
		for(int j=i+1;j<=stu;j++)
		{
			if(grade[i]<grade[j])
			{
				if(grade[i]==a1)
				{
					wei=j;
				}
				if(grade[j]==a1)
				{
					wei=i;
				}
				swap(grade[i],grade[j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				cnt++;
				num[j][i]=cnt;
				if(cnt==wei)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				cnt++;
				num[j][i]=cnt;
				if(cnt==wei)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}			
		}
	}
	return 0;
}
