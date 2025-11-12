#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 5;

struct Node{
	ll v[5];
	ll cha;
}arr[N];
ll n;
vector <Node> sep[5];
ll mx(Node x)
{
	ll m = max(x.v[1],max(x.v[2],x.v[3]));
	return m;	
}
ll wimax(Node x)
{
	ll m = mx(x);
	for(ll j = 1;j <= 3;j++)
		if(m == x.v[j])
			return j;
	return -1;
}
bool cmp1(const Node& A,const Node& B)
{
	return mx(A) > mx(B);
}
bool cmp2(const Node& A,const Node& B)
{
	return A.cha < B.cha;
}
void func(void)
{
	memset(arr,0x0,sizeof arr);
	for(ll i = 0;i < 5;i++)
		sep[i].clear();
	scanf("%lld",&n);
	for(ll i = 1;i <= n;i++)
	{
		for(ll j = 1;j <= 3;j++)
			scanf("%lld",&arr[i].v[j]);
	}
	sort(arr + 1,arr + n + 1,cmp1);
	ll ans = 0;
	for(ll i = 1;i <= n;i++)
	{
		sep[wimax(arr[i])].push_back(arr[i]);
		ans += mx(arr[i]);
	}
	for(ll j = 1;j <= 3;j++)
	{
		if(sep[j].size() > n / 2)
		{
			ll pp = sep[j].size() - n / 2;
			for(ll i = 0;i < sep[j].size();i++)
			{
				ll sum = 0,w = wimax(sep[j][i]);
				for(ll k = 1;k <= 3;k++)
					if(k != w)
						sum = max(sum,sep[j][i].v[k]);
				sep[j][i].cha = mx(sep[j][i]) - sum;
			}
			sort(sep[j].begin(),sep[j].end(),cmp2);
			for(ll i = 0;i < pp;i++)
				ans -= sep[j][i].cha;
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)
		func();
	return 0;
}
