#include <bits/stdc++.h>
using namespace std;

struct node
{
	int a,b,c;
	int pre()
	{
		if (a >= b && a >= c)
			if (b >= c) return a - b;
			else return a - c;
		else if (b >= a && b >= c)
			if (a >= c) return b - a;
			else return b - c;
		else
			if (a >= b) return c - a;
			else return c - b;
	}
	friend bool operator < (node x,node y)
	{
		return x.pre() > y.pre();
	}
};

priority_queue <node> qa,qb,qc;
int n,T;

void sol()
{
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		node cur;
		cin >> cur.a >> cur.b >> cur.c;
		if (cur.a >= cur.b && cur.a >= cur.c)
		{
			if (qa.size() == 0)
			{
				qa.push(cur);
				continue;
			}
			node temp = qa.top();
			if (qa.size() * 2 < n) qa.push(cur);
			else if (temp.pre() <= cur.pre())
			{
				node change = temp;
				qa.pop();
				qa.push(cur);
				if (change.b < change.c && qc.size() * 2 < n) qc.push(change);
				else qb.push(change);
			}
			else
				if (cur.b < cur.c && qc.size() * 2 < n) qc.push(cur);
				else qb.push(cur);
		}
		else if (cur.b >= cur.a && cur.b >= cur.c)
		{
			if (qb.size() == 0)
			{
				qb.push(cur);
				continue;
			}
			node temp = qb.top();
			if (qb.size() * 2 < n) qb.push(cur);
			else if (temp.pre() <= cur.pre())
			{
				node change = temp;
				qb.pop();
				qb.push(cur);
				if (change.a < change.c && qc.size() * 2 < n) qc.push(change);
				else qa.push(change);
			}
			else
				if (cur.a < cur.c && qc.size() * 2 < n) qc.push(cur);
				else qa.push(cur);
		}
		else
		{
			if (qc.size() == 0)
			{
				qc.push(cur);
				continue;
			}
			node temp = qc.top();
			if (qc.size() * 2 <= n) qc.push(cur);
			else if (temp.pre() < cur.pre())
			{
				node change = temp;
				qc.pop();
				qc.push(cur);
				if (change.b < change.a && qa.size() * 2 < n) qa.push(change);
				else qb.push(change);
			}
			else
				if (cur.b < cur.a && qa.size() * 2 < n) qa.push(cur);
				else qb.push(cur);
		}
	}
	long long ans = 0;
	while (qa.size())
	{
		ans += qa.top().a;
		qa.pop();
	}
	while (qb.size())
	{
		ans += qb.top().b;
		qb.pop();
	}
	while (qc.size())
	{
		ans += qc.top().c;
		qc.pop();
	}
	cout << ans << "\n";
}

int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while (T --) sol();
	return 0;
}
