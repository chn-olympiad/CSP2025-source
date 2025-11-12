#include<bits/stdc++.h>
using namespace std;
int n,T,ma,sum,cnt[4];
struct node
{
	int x,b,c;
}a[100005];
bool cmp(node i,node j)
{
	return i.x>j.x;
}
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].b>>a[i].c;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		{
			sum+=a[i].x;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
