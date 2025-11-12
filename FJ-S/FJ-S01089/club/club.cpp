#include<bits/stdc++.h>
using namespace std;
struct node{
	int man[4];
}a[100005];
int t,n,d[100005][4];
bool flag[2];//B A
bool paixu(node a,node b)
{
	for(int i=1;i<=3;i++)
		if(a.man[i]<b.man[i])
			return 0;
	return 1;
}
void fA()
{
	int sum=0;
	for(int i=1;i<=n/2;i++)
		sum+=a[i].man[1];
	cout<<sum;
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(d,0,sizeof d);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].man[1];
			cin>>a[i].man[2];
			if(!flag[1])
			{
				if(a[i].man[2]!=0)
					flag[1]=1;
			}
			cin>>a[i].man[3];
			if(!flag[0])
			{
				if(a[i].man[3]!=0)
					flag[0]=1;
			}
		}
		sort(a+1,a+n+1,paixu);
		if(!flag[0])
		{
			if(!flag[1])
			{
				fA();
				continue;
			}
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
