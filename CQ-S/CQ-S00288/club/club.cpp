/*
club
感觉 $\dfrac{n}{2}$ 是很古怪的限制。
显然的贪心是，每个人选满意度最大的，但是这样会在极限情况下死掉。
发现只要选定某个团有 $\dfrac{n}{2}$ 个人，剩下两个团就不需要管限制了。
所以 DP，要么选择某团，要么选择剩下两团中较大的那个，发现平方和三次方一个吊分。
那么先贪完，再跑一次的时候从中删去若干个，这个仍然能贪，就做完了。
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=100010;
priority_queue<int>pq[3];
int a[N][3];
inline void solve()
{
	int n;
	scanf("%d",&n);
	for(int d=0;d<3;d++)while(!pq[d].empty())pq[d].pop();
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int d=0;d<3;d++)scanf("%d",&a[i][d]);
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])sum+=a[i][0],pq[0].push(max(a[i][1],a[i][2])-a[i][0]);
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])sum+=a[i][1],pq[1].push(max(a[i][0],a[i][2])-a[i][1]);
		else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1])sum+=a[i][2],pq[2].push(max(a[i][0],a[i][1])-a[i][2]);
	}
	for(int d=0;d<3;d++)while(pq[d].size()>n/2)sum+=pq[d].top(),pq[d].pop();
	printf("%lld\n",sum);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}