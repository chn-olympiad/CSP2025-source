#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct data1{int id,val;}a[N][5];
bool cmp(data1 x,data1 y){return x.val>y.val;}
int cnt[5];
priority_queue<int,vector<int>,greater<int>>heap[5];
void solve()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1].val>>a[i][2].val>>a[i][3].val;
		a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
		sort(a[i]+1,a[i]+4,cmp);
		cnt[a[i][1].id]++,ans+=a[i][1].val;
		heap[a[i][1].id].push(a[i][1].val-a[i][2].val);
	}
	int tmp=1;
	if(cnt[2]>cnt[tmp])tmp=2;
	if(cnt[3]>cnt[tmp])tmp=3;
	while(cnt[tmp]>n/2)ans-=heap[tmp].top(),cnt[tmp]--,heap[tmp].pop();
	cout<<ans<<'\n';
	cnt[1]=cnt[2]=cnt[3]=0;
	while(!heap[1].empty())heap[1].pop();
	while(!heap[2].empty())heap[2].pop();
	while(!heap[3].empty())heap[3].pop();
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	for(;T;T--)solve();
	return 0;
}
