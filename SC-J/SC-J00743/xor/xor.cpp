#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
ll a[N] = {};
ll n, k;
vector<ll> pre(N);
ll yihuohe(int l, int r)
{
	ll res = pre[r] ^ pre[l - 1];
	return res;
}

struct node
{
	ll l, r;
};
ll cnt;
vector<node> queryr(N);
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for(ll i = 0; i < n; i++)
	{
		cin >> a[i]; 
		pre[i] = pre[i - 1] ^ a[i];
	}
	//cout << "--------------1------------" << '\n';
	for(ll i = 0; i < n; i++)
	{
		for(ll j = i; j < n; j++)
		{
			if(yihuohe(i, j) == k)
			{
				queryr[cnt].l = i;
				queryr[cnt].r = j;
				cnt++;
			}
		}
	}
	//cout << "------------2--------------" << '\n';
	for(ll i = 0; i < cnt; i++)
	{
		for(ll j = 0; j < cnt; j++)
		{
			if(queryr[i].l < queryr[j].l) swap(queryr[i], queryr[j]);
			if(queryr[i].l == queryr[j].l)
			{
				if(queryr[i].r < queryr[j].r) swap(queryr[i], queryr[j]);
			}
		}
	}
	//cout << "-------------3-------------" << '\n';
	ll ans = 0;
	ll prer = 0;
	for(ll i = 0; i < cnt; i++)
	{
		ll cnt2 = 1;
		prer = queryr[i].r;
		for(ll j = i + 1; j < cnt; j++)
		{
			if(queryr[j].l <= prer) continue;
			prer = queryr[j].r;
			cnt2++;
		}
		ans = max(ans, cnt2);
	}
	cout << ans;
	return 0;
}