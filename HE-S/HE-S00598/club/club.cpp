#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
using namespace std;
const int Imax=0x7fffffff;
const long long LLmax=0x7fffffffffffffff;
const int N=1e5+5;
int T;
int n;
int a[N][3];
priority_queue<int> p,q,r;
int cnt0,cnt1,cnt2;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		while(!p.empty()) p.pop();
		while(!q.empty()) q.pop();
		while(!r.empty()) r.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		intt ans=0;
		for(int i=1;i<=n;i++)
		{
			if(max({a[i][0],a[i][1],a[i][2]})==a[i][0])
				ans+=a[i][0],p.push(max(a[i][1],a[i][2])-a[i][0]);
			else if(max({a[i][0],a[i][1],a[i][2]})==a[i][1])
				ans+=a[i][1],q.push(max(a[i][0],a[i][2])-a[i][1]);
			else
				ans+=a[i][2],r.push(max(a[i][0],a[i][1])-a[i][2]);
		}
		while(p.size()>n/2) ans+=p.top(),p.pop();
		while(q.size()>n/2) ans+=q.top(),q.pop();
		while(r.size()>n/2) ans+=r.top(),r.pop();
		printf("%lld\n",ans);
	}
	return 0;
}
