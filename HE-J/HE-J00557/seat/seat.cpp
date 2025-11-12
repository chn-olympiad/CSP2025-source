#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int num,score;
}a[500];
bool cmp(node x,node y)
{
	return x.score>y.score;
}
int main()
{
//	Why my *.cpp files' icon turns notepad?
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].score);
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,ans=1,doru=1,sum=n*m;
	while(sum--)
	{
		if(a[ans].num==1)
		{
			printf("%d %d",y,x);
			return 0;
		}
		if(x==n&&doru==1)
		{
			y++;
			doru=2;
			ans++;
			continue;
		}
		if(x==1&&doru==2)
		{
			y++;
			doru=1;
			ans++;
			continue;
		}
		if(doru==1) x++;
		else x--;
		ans++;
	}
	return 0;
}
