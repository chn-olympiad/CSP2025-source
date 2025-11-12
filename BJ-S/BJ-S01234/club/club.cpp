#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,dp[205][5][105],Max,n;
struct node
{
	int d1,d2,d3;
}a[100005];
bool cmp(node x,node y)
{
	return x.d1>y.d1;
}
void work(int pos,int c1,int c2,int c3,int ans)
{
	int i;
	if(pos>n)
	{
		Max=max(Max,ans);
		return;
	}
	if(c1<n/2)
		work(pos+1,c1+1,c2,c3,ans+a[pos].d1);
	if(c2<n/2)
		work(pos+1,c1,c2+1,c3,ans+a[pos].d2);
	if(c3<n/2)
		work(pos+1,c1,c2,c3+1,ans+a[pos].d3);
}
int main()
{
	int i,j,k,l;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int cnt=0;
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
		if(n==2)
			cout<<max(max(a[1].d1+a[2].d2,a[1].d1+a[2].d3),max(max(a[1].d2+a[2].d1,a[1].d3+a[2].d1),max(a[1].d2+a[2].d3,a[1].d3+a[2].d2)))<<endl;
		else if(n==4)
		{
			Max=0;
			work(1,0,0,0,0);
			cout<<Max<<endl;
		}
		else
		{
			sort(a+1,a+1+n,cmp);
			for(i=1;i<=n/2;i++)
				cnt+=a[i].d1;
			cout<<cnt<<endl;
		}
	}
	return 0;
}