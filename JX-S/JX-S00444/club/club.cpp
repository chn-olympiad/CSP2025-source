#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node2
{
	int i,s;
};
struct node{
	node2 s[3];
}a[N];
bool cmp(node x,node y)
{
	return (x.s[0].s-x.s[1].s)>(y.s[0].s-y.s[1].s);
}
int t,n,cnt[4];
void sor(int i)
{
	if(a[i].s[0].s<a[i].s[1].s)swap(a[i].s[0],a[i].s[1]);
	if(a[i].s[0].s<a[i].s[2].s)swap(a[i].s[0],a[i].s[2]);
	if(a[i].s[1].s<a[i].s[2].s)swap(a[i].s[1],a[i].s[2]);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		for(int i=0;i<=3;i++)cnt[i]=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].s[0].s>>a[i].s[1].s>>a[i].s[2].s;
			a[i].s[0].i=1,a[i].s[1].i=2,a[i].s[2].i=3;
			sor(i);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(cnt[a[i].s[0].i]<n/2)
			{
				ans+=a[i].s[0].s;
				cnt[a[i].s[0].i]++;
			}
			else ans+=a[i].s[1].s;
		}
		cout<<ans<<endl;
	}
	return 0;
}
