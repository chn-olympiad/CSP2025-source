#include <bits/stdc++.h>
using namespace std;
int t;
int n;
long long ans = 0;
struct cy
{
	int a;
	int b;
	int c;
	int max;
	int sec;
	int thi;
	int maxidx;
	int secidx;
	int thiidx;
	int max_sec;
	int sec_thi;
};
struct sl
{
	int max;
	int sec;
	int thi;
};
cy a[100010];
sl ssl[4];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for(int qq = 1; qq <= t; qq++)
    {
		bool jg[200010];
		bool jjg[200010];
    	memset(ssl, 0, sizeof(ssl));
    	memset(jg, false, sizeof(jg));
    	memset(jjg, false, sizeof(jjg));
    	memset(a, 0, sizeof(a));
        cin >> n;
        int zd = n / 2;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].a >> a[i].b >> a[i].c;
            if(a[i].a >= a[i].b && a[i].a >= a[i].c)  //a > b, a > c
            {
            	a[i].max = a[i].a;
            	a[i].maxidx = 1;
            	if(a[i].b >= a[i].c) //a > b > c
            	{
            		a[i].sec = a[i].b;
            		a[i].secidx = 2;
            		a[i].thi = a[i].c;
					a[i].thiidx = 3;
					a[i].max_sec = abs(a[i].a - a[i].b);
					a[i].sec_thi = abs(a[i].b - a[i].c);
				}
				else // a > c > b
				{
					a[i].sec = a[i].c;
            		a[i].secidx = 3;
            		a[i].thi = a[i].b;
					a[i].thiidx = 2;
					a[i].max_sec = abs(a[i].a - a[i].c);
					a[i].sec_thi = abs(a[i].c - a[i].b);
				}

			}
			else if(a[i].b >= a[i].a && a[i].b >= a[i].c)  //b > a, b > c
            {
            	a[i].max = a[i].b;
            	a[i].maxidx = 2;
            	if(a[i].a >= a[i].c) //b > a > c
            	{
            		a[i].sec = a[i].a;
            		a[i].secidx = 1;
            		a[i].thi = a[i].c;
					a[i].thiidx = 3;
					a[i].max_sec = abs(a[i].b - a[i].a);
					a[i].sec_thi = abs(a[i].a - a[i].c);
				}
				else // b > c > a
				{
					a[i].sec = a[i].c;
            		a[i].secidx = 3;
            		a[i].thi = a[i].a;
					a[i].thiidx = 1;
					a[i].max_sec = abs(a[i].b - a[i].c);
					a[i].sec_thi = abs(a[i].c - a[i].a);
				}

			}
			else if(a[i].c >= a[i].a && a[i].c >= a[i].b)  //c > a, c > b
            {
            	a[i].max = a[i].c;
            	a[i].maxidx = 3;
            	if(a[i].a >= a[i].b) //c > a > b
            	{
            		a[i].sec = a[i].a;
            		a[i].secidx = 1;
            		a[i].thi = a[i].b;
					a[i].thiidx = 2;
					a[i].max_sec = abs(a[i].c - a[i].a);
					a[i].sec_thi = abs(a[i].a - a[i].b);
				}
				else // c > b > a
				{
					a[i].sec = a[i].b;
            		a[i].secidx = 2;
            		a[i].thi = a[i].a;
					a[i].thiidx = 1;
					a[i].max_sec = abs(a[i].c - a[i].b);
					a[i].sec_thi = abs(a[i].b - a[i].a);
				}

			}
        }
        for(int i = 1; i <= n; i++)
        {
        	ssl[a[i].maxidx].max++;
        	//ssl[a[i].secidx].sec++;
        	//ssl[a[i].thiidx].thi++;
		}
		if(ssl[1].max <= zd && ssl[2].max <= zd && ssl[3].max <= zd) //直接输
		{
			for(int i = 1; i <= n; i++) ans += a[i].max;
			cout << ans << endl;
			ans = 0;
		}
		else //有超
		{

			memset(jg, false, sizeof(jg));
			if(ssl[1].max > zd) //1最大超了
			{
				int xj = ssl[1].max - zd;//需要减的数量
				while(xj > 0)
				{
					int p = 0;
					int mina = 0x3f3f3f3f;
					for(int i = 1; i <= n; i++)
					{
						if(a[i].maxidx == 1)
						{
							if(mina > a[i].max_sec && !jg[i])
							{
								mina = a[i].max_sec;
								p = i;
								xj--;
								ssl[1].max--;
								ssl[1].sec++;
							}
						}

						a[p].maxidx = a[p].secidx;
						a[p].max = a[p].sec; //减
						jg[p] = true;

				}

			}
			if(ssl[2].max > zd) //2最大超了
			{
				int xj = ssl[2].max - zd;//需要减的数量
				while(xj > 0)
				{
					int p = 0;
					int mina = 0x3f3f3f3f;
					for(int i = 1; i <= n; i++)
					{
						if(a[i].maxidx == 2)
						{
							if(mina > a[i].max_sec && !jg[i])
							{
								mina = a[i].max_sec;
								p = i;
								xj--;
								ssl[2].max--;
								ssl[2].sec++;
							}
						}
					}
						a[p].maxidx = a[p].secidx;
						a[p].max = a[p].sec; //减
						jg[p] = true;

				}

			}
			if(ssl[3].max > zd) //3最大超了
			{
				int xj = ssl[3].max - zd;//需要减的数量
				while(xj > 0)
				{
					int p = 0;
					int mina = 0x3f3f3f3f;
					for(int i = 1; i <= n; i++)
					{
						if(a[i].maxidx == 3)
						{
							if(mina > a[i].max_sec && !jg[i])
							{
								mina = a[i].max_sec;
								p = i;
								xj--;
								ssl[3].max--;
								ssl[3].sec++;
							}
						}
					}
						a[p].maxidx = a[p].secidx;
						a[p].max = a[p].sec; //减
						jg[p] = true;

				}

			}

			for(int i = 1; i <= n; i++)
			{
				ans += a[i].max;
			}
			cout << ans << endl;
			ans = 0;
		}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
