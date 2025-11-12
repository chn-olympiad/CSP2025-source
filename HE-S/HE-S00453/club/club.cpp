#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fr(a,b,c) for(c=a;c<=b;c++)
#define rf(a,b,c) for(c=a;c>=b;c--)
#define I_AK_CSP ios_base::sync_with_stdio(0);cin.tie(0) 
#define MAXN 2000001
using namespace std;
ll t, n, a[MAXN][3], h, i, j, k,k2,k3 ,sn1, sn2, sy, book[MAXN];
int main()
{
	I_AK_CSP;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		priority_queue<pair<ll, pair<ll, ll>>> q;
		cin >> n;
		fr(1, n, i)
		{
			fr(1, 3, j)
			{
				cin >> a[i][j];
			}
		}
		sn1=0,sn2=0,h=0,k=0;
		fr(1, n, i)
		{
			k += a[i][1];
			book[i] = 0;
			fr(2, 3, j)
			{
				q.push({a[i][j] - a[i][1], {i, j}});
			}
		}
		sy=n;
		while(q.size())
		{
			if(sn1 + sn2 + h == n)break;
			auto ls = q.top();                                                  
			q.pop();
			if(book[ls.second.first])continue;
			if(ls.first < 1 && sy <= (n >> 1))break;
			if(a[ls.second.first][2] == a[ls.second.first][3])
			{
				h++,sy--;
				book[ls.second.first] = 1;
				k += ls.first;
			}
			else
			{
				if(ls.second.second & 1)
				{
					if(sn1 < (n >> 1))
					{
						sn1++,sy--;
						book[ls.second.first] = 1;
						k += ls.first;
					}
				}
				else
				{
					if(sn2 < (n >> 1))
					{
						sn2++,sy--;
						book[ls.second.first] = 1;
						k += ls.first;
					}
				}
			}
		}
		//k2
		while(q.size())q.pop();
		sn1=0,sn2=0,h=0,k2=0;
		fr(1, n, i)
		{
			k2 += a[i][2];
			book[i] = 0;
			fr(1, 3, j)
			{
				if(j!=2)q.push({a[i][j] - a[i][2], {i, j}});
			}
		}
		sy=n;
		while(q.size())
		{
			if(sn1 + sn2 + h == n)break;
			auto ls = q.top();                                                  
			q.pop();
			if(book[ls.second.first])continue;
			if(ls.first < 1 && sy <= (n >> 1))break;
			if(a[ls.second.first][1] == a[ls.second.first][3])
			{
				h++,sy--;
				book[ls.second.first] = 1;
				k2 += ls.first;
			}
			else
			{
				if(ls.second.second == 1)
				{
					if(sn1 < (n >> 1))
					{
						sn1++,sy--;
						book[ls.second.first] = 1;
						k2 += ls.first;
					}
				}
				else
				{
					if(sn2 < (n >> 1))
					{
						sn2++,sy--;
						book[ls.second.first] = 1;
						k2 += ls.first;
					}
				}
			}
		}
		//k3
		while(q.size())q.pop();
		sn1=0,sn2=0,h=0,k3=0;
		fr(1, n, i)
		{
			k3 += a[i][3];
			book[i] = 0;
			fr(1, 2, j)
			{
				q.push({a[i][j] - a[i][3], {i, j}});
			}
		}
		sy=n;
		while(q.size())
		{
			if(sn1 + sn2 + h == n)break;
			auto ls = q.top();                                                  
			q.pop();
			if(book[ls.second.first])continue;
			if(ls.first < 1 && sy <= (n >> 1))break;
			if(a[ls.second.first][1] == a[ls.second.first][2])
			{
				h++,sy--;
				book[ls.second.first] = 1;
				k3 += ls.first;
			}
			else
			{
				if(ls.second.second & 2)
				{
					if(sn1 < (n >> 1))
					{
						sn1++,sy--;
						book[ls.second.first] = 1;
						k3 += ls.first;
					}
				}
				else
				{
					if(sn2 < (n >> 1))
					{
						sn2++,sy--;
						book[ls.second.first] = 1;
						k3 += ls.first;
					}
				}
			}
		}
		cout << max(k,max(k2,k3)) << "\n";
	}
	return 0;
}
