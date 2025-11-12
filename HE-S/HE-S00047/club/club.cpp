#include <bits/stdc++.h>
using namespace std;

struct node
{
	int x,y,z;
}a[100005];

struct stu
{
	int k,q,w;
}b[100005];

bool cmp(stu x,stu y)
{
	return x.k > y.k;
}
struct no
{
    int l,p,h;
}c[100005];
bool cp(no xx,no yy)
{
    return xx.p < yy.p;
}



int k[5];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	scanf("%d",&t);

	while(t--)
	{
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(k,0,sizeof k);

		int n;
		scanf("%d",&n);

        int jj[100005] = {};
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			int maxn = 0,mp = 0;
			if(a[i].x >= a[i].y) maxn = a[i].x,mp = 1;
			else maxn = a[i].y,mp = 2;
			if(maxn < a[i].z) maxn = a[i].z,mp = 3;

			b[i].k = maxn;
			b[i].q = mp;
			b[i].w = i;
			jj[i] = b[i].q;
			ans += maxn;
		}

		sort(b+1,b+n+1,cmp);

		for(int i = 1;i <= n;i++)
		{
			k[b[i].q]++;
		}

		if(k[1] <= n/2 && k[2] <= n/2 && k[3] <= n/2)
		{
			printf("%d\n",ans);
			continue;
		}

		int wa = 0;
		if(k[1] > n/2) wa = 1;
		if(k[2] > n/2) wa = 2;
		if(k[3] > n/2) wa = 3;

        int d[100005] = {};
		for(int i = 1;i <= n;i++)
		{
			if(b[i].q == 1)
			{
				c[i].p = max(a[b[i].w].y,a[b[i].w].z);
			}
			else if(b[i].q == 2)
			{
				c[i].p = max(a[b[i].w].x,a[b[i].w].z);
			}
			else
			{
				c[i].p = max(a[b[i].w].x,a[b[i].w].y);
			}
			c[i].p = b[i].k - c[i].p;
			c[i].l = jj[b[i].w];
			c[i].h = i;
			d[i] = c[i].l;
		}

		sort(c+1,c+n+1,cp);

		int nn = 0;
		for(int i = 1;i <= n;i++)
        {
            if(d[c[i].h] == wa)
            {
                ans -= c[i].p;
                nn++;
                if(nn == k[wa]-n/2) break;
            }
        }

		printf("%d\n",ans);
	}


	return 0;
}
