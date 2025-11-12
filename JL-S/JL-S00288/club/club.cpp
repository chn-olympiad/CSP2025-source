#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
int a[N][4],cnt[5];
//pair<int,int> b[N][4];
struct node{
	pair<int,int> x[3];
	/*bool operator<(const node &cmp) const{
		return (x[1]-x[2])>()cmp.x[1]-cmp.x[2];
	}*/
}b[N];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.first>b.first;
}
bool cmp2(node a,node b)
{
	return a.x[1].first-a.x[2].first>b.x[1].first-b.x[2].first;
}
void work()
{
	cnt[1]=cnt[2]=cnt[3]=0;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++) 
		{
			cin>>a[i][j];
			b[i].x[j]={a[i][j],j};
		}
		//b[i].x={0,a[i][1],a[i][2],a[i][3]};
		sort(b[i].x+1,b[i].x+4,cmp);
	}
	sort(b+1,b+1+n,cmp2);
	for(int i=1;i<=n;i++)
	{
		if(cnt[b[i].x[1].second]>=n/2) ans+=b[i].x[2].first,cnt[b[i].x[2].second]++;
		else ans+=b[i].x[1].first,cnt[b[i].x[1].second]++;
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		work();
	}
	return 0;
}
