#include<bits/stdc++.h>
using namespace std;

int a[500005];
int n, m, p, u;
long long cnt=1, k;

struct qj{
    int s;
    int e;
}q[200000000];

bool cmp(qj x, qj y)
{
    if(x.e != y.e)
    {
        return x.e < y.e;
    }else
    {
        return x.s > y.s;
    }
}

int main()
{
	freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  freopen("xor.out","w",stdout);
    ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++)
	{
	    k = 0;
		for(int j=i; j<=n; j++)
		{
			k = (k^a[j]);
			if(k == m)
            {
                q[++p].s = i;
                q[p].e = j;
            }
		}
	}
	sort(q+1, q+1+p, cmp);
	u = q[1].e;
	for(int i=2; i<=p; i++)
    {
        if(q[i].s < u)
        {
            cnt++;
            u = q[i].e;
        }
    }
	cout << cnt;
    return 0;
}
