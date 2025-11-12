#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct did
{
	int x,id;
	bool operator<(const did &b)const{return x<b.x;}
};
struct node
{
	did a[4];
	int v;
	bool operator<(const node &b)const{return v>b.v;}
}s[N];
int t,n,kong[4],ans;
void work()
{
	for(int i=1;i<=3;i++)kong[i]=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>s[i].a[j].x;
			s[i].a[j].id=j;
		}
		sort(s[i].a+1,s[i].a+1+3);
		s[i].v=s[i].a[3].x-s[i].a[2].x;
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)
	{
		int tmp=s[i].a[3].x,sb=s[i].a[3].id;
		if(kong[sb]==n/2)tmp=s[i].a[2].x,sb=s[i].a[2].id;
//		cout<<"wtf: "<<i<<' '<<tmp<<' '<<sb<<'\n';
		ans+=tmp;
		kong[sb]++;
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)work();
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
