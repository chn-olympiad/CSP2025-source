#include<cstdio>
#include<algorithm>
using namespace std;
int nums[10000]={0},id[10000]={0};
bool cmp(int a,int b)
{
	return nums[a]>nums[b];
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,row,lie;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",nums+i);
		id[i]=i;
	}
	sort(id+1,id+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(id[i]==1)
		{
			row=i%(2*n),lie=(i+n-1)/n;
			break;
		}
	}
	if(row==0)
	{
		row=n;
	}
	else if(row>n)
	{
		row=n-(row-n-1);
	}
	printf("%d %d",lie,row);
	return 0;
}
