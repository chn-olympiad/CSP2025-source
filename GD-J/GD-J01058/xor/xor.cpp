#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

const ll N = 5 * 1e5 + 5;
ll n, k;
ll prea[N] = {}; // 前面 x 项的异或和
ll match[N] = {}; 

ll xxor(ll x, ll dpt)
{
	prea[dpt] = (prea[dpt - 1] ^ x);
}

vector<pair<ll, ll> > p;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

bool comp(ll x, ll y)
{
	if((prea[x] ^ prea[y]) == k) return true;
	else return false;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(ll i = 1; i <= n; i++)
	{
		ll xx;
		cin >> xx;
		xxor(xx, i);
	}
	for(ll i = 0; i < n; i++)
	{
		for(ll j = i + 1; j <= n; j++)
		{
			if(comp(i, j) == true)
			{
				p.push_back({i + 1, j});
			}
		}
	}
	sort(p.begin(), p.end(), cmp);
	/*
	for(int i = 0; i < p.size(); i++)
	{
		cout << p[i].first << " " << p[i].second << endl;
	}
	*/
	int now_bitt = n + 1, cnt = 0;
	for(int i = 0; i < p.size(); i++)
	{
		if(p[i].second < now_bitt)
		{
			cnt++;
			now_bitt = p[i].first;
		}
	}
	cout << cnt << endl;
	return 0;
}
