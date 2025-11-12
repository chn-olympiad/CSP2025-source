//club.cpp
#include<bits/stdc++.h>
using namespace std;
struct Num{
	int x,y,z;
}a[10010];
bool cmp1(Num a,Num b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int maxn=n/2;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp1);
		int ans=0;
		for(int i=1;i<=maxn;i++)
			ans+=a[i].x;
		cout<<ans<<'\n';
	}
	return 0;
}
