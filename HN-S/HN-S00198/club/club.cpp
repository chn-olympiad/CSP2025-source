#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t[5];
long long sum;
struct node{
	int ma,num,c;
}a[4][N];
bool cmp(node x,node y)
{
	return x.c>y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		t[1]=t[2]=t[3]=sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x1,x2,x3;
			cin>>x1>>x2>>x3;
			if(x1>=x2&&x1>=x3)
			{
				a[1][++t[1]].ma=x1;
				a[1][t[1]].c=x1-max(x2,x3);
				sum+=a[1][t[1]].ma;
			}
			else if(x2>=x1&&x2>=x3)
			{
				a[2][++t[2]].ma=x2;
				a[2][t[2]].c=x2-max(x1,x3);
				sum+=a[2][t[2]].ma;
			}
			else
			{
				a[3][++t[3]].ma=x3;
				a[3][t[3]].c=x3-max(x1,x2);
				sum+=a[3][t[3]].ma;
			}
		}
		int x;
		if(t[1]>n/2)x=1;
		else if(t[2]>n/2)x=2;
		else x=3;
		sort(a[x]+1,a[x]+t[x]+1,cmp);
		for(int i=n/2+1;i<=t[x];i++)
		{
				sum-=a[x][i].c;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
