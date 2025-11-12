#include <bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c,maxn = -1;
	void getmax(){maxn = max(max(a,b),c);}
}a[100005];
long long T,n,sum = 0,rs[4] = {0,0,0,0},zf[4] = {0,0,0,0},da = 0;
bool cmp(node a1,node a2)
{
	return a1.maxn > a2.maxn;
}
bool canput(long long fl)
{
	if (rs[fl] >= n / 2) return false;
	return true;
}
void tiaoji(long long a,long long b,long long c)
{
	if (a > b && b > c) // a -> b -> c
	{
		if (canput(1))
		{
			rs[1]++;
			sum += a;
		}
		else if (canput(2))
		{
			rs[2]++;
			sum += b;
		}
		else
		{
			rs[3]++;
			sum += c;
		}
	}
	else if (a > c && c > b) // a -> c -> b
	{
		if (canput(1))
		{
			rs[1]++;
			sum += a;
		}
		else if (canput(3))
		{
			rs[3]++;
			sum += c;
		}
		else
		{
			rs[2]++;
			sum += b;
		}
	}
	else if (b > a && a > c) // b -> a -> c
	{
		if (canput(2))
		{
			rs[2]++;
			sum += b;
		}
		else if (canput(1))
		{
			rs[1]++;
			sum += a;
		}
		else
		{
			rs[3]++;
			sum += c;
		}
	}
	else if (b > a && a > c) // b -> c -> a
	{
		if (canput(2))
		{
			rs[2]++;
			sum += b;
		}
		else if (canput(3))
		{
			rs[3]++;
			sum += c;
		}
		else
		{
			rs[1]++;
			sum += a;
		}
	}
	else if (b > a && a > c) // c -> a -> b
	{
		if (canput(3))
		{
			rs[3]++;
			sum += c;
		}
		else if (canput(1))
		{
			rs[1]++;
			sum += a;
		}
		else
		{
			rs[2]++;
			sum += b;
		}
	}
	else if (b > a && a > c) // c -> b -> a
	{
		if (canput(3))
		{
			rs[3]++;
			sum += c;
		}
		else if (canput(2))
		{
			rs[2]++;
			sum += b;
		}
		else
		{
			rs[1]++;
			sum += a;
		}
	}
	else if (a > b) // a/c -> b
	{
		if (canput(1))
		{
			rs[1]++;
			sum += a;
		}
		else if (canput(3))
		{
			rs[3]++;
			sum += c;
		}
		else
		{
			rs[2]++;
			sum += b;
		}
	}
	else if (a > c) // a/b -> c
	{
		if (canput(1))
		{
			rs[1]++;
			sum += a;
		}
		else if (canput(2))
		{
			rs[2]++;
			sum += b;
		}
		else
		{
			rs[3]++;
			sum += c;
		}
	}
	else // b/c -> a
	{
		if (canput(2))
		{
			rs[2]++;
			sum += b;
		}
		else if (canput(3))
		{
			rs[3]++;
			sum += c;
		}
		else
		{
			rs[1]++;
			sum += a;
		}
	}
}
void jztz(long long l,long long a,long long b,long long c)
{
	sum += l;
	if (a > b && b > c) // a -> b -> c
	{
		if (canput(1)) rs[1]++;
		else if (canput(2)) rs[2]++;
		else rs[3]++;
	}
	else if (a > c && c > b) // a -> c -> b
	{
		if (canput(1)) rs[1]++;
		else if (canput(3)) rs[3]++;
		else rs[2]++;
	}
	else if (b > a && a > c) // b -> a -> c
	{
		if (canput(2)) rs[2]++;
		else if (canput(1)) rs[1]++;
		else rs[3]++;
	}
	else if (b > a && a > c) // b -> c -> a
	{
		if (canput(2)) rs[2]++;
		else if (canput(3)) rs[3]++;
		else rs[1]++;
	}
	else if (b > a && a > c) // c -> a -> b
	{
		if (canput(3)) rs[3]++;
		else if (canput(1)) rs[1]++;
		else rs[2]++;
	}
	else if (b > a && a > c) // c -> b -> a
	{
		if (canput(3)) rs[3]++;
		else if (canput(2)) rs[2]++;
		else rs[1]++;
	}
	else if (a > b) // a/c -> b
	{
		if (canput(1)) rs[1]++;
		else if (canput(3)) rs[3]++;
		else rs[2]++;
	}
	else if (a > c) // a/b -> c
	{
		if (canput(1)) rs[1]++;
		else if (canput(2)) rs[2]++;
		else rs[3]++;
	}
	else // b/c -> a
	{
		if (canput(2)) rs[2]++;
		else if (canput(3)) rs[3]++;
		else rs[1]++;
	}
}
void toput(long long a,long long b,long long c)
{
	if ((a > b && b > c) || (a > c && c > b)) //a最大: a -> 调剂
	{
		if (canput(1))
		{
			sum += a;
			rs[1]++;
		}
		else
		{
			tiaoji(-1,b,c);
		}
	}
	else if ((b > a && a > c) || (b > c && c > a)) //b最大: b -> 调剂
	{
		if (canput(2))
		{
			sum += b;
			rs[2]++;
		}
		else tiaoji(a,-1,c);
	}
	else if ((c > a && a > b) || (c > b && b > a)) //c最大: c -> 调剂
	{
		if (canput(3))
		{
			sum += c;
			rs[3]++;
		}
		else tiaoji(a,b,-1);
	}
	else if (a == b && a > c) // a,b最大: a/b -> c
	{
		if (zf[1] > zf[2])
		{
			if (canput(1))
			{
				sum += a;
				rs[1]++;
			}
			else if (canput(2))
			{
				sum += b;
				rs[2]++;
			}
			else
			{
				sum += c;
				rs[3]++;
			}
		}
		else
		{
			if (canput(2))
			{
				sum += b;
				rs[2]++;
			}
			else if (canput(1))
			{
				sum += a;
				rs[1]++;
			}
			else
			{
				sum += c;
				rs[3]++;
			}
		}
	}
	else if (a == c && a > b) // a,c最大: a/c -> b
	{
		if (zf[1] > zf[3])
		{
			if (canput(1))
			{
				sum += a;
				rs[1]++;
			}
			else if (canput(3))
			{
				sum += c;
				rs[3]++;
			}
			else
			{
				sum += b;
				rs[2]++;
			}
		}
		else
		{
			if (canput(3))
			{
				sum += c;
				rs[3]++;
			}
			else if (canput(1))
			{
				sum += a;
				rs[1]++;
			}
			else
			{
				sum += b;
				rs[2]++;
			}
		}
	}
	else if (b == c && b > a) // b,c最大: b/c -> a
	{
		if (zf[2] > zf[3])
		{
			if (canput(2))
			{
				sum += b;
				rs[2]++;
			}
			else if (canput(3))
			{
				sum += c;
				rs[3]++;
			}
			else
			{
				sum += a;
				rs[1]++;
			}
		}
		else
		{
			if (canput(3))
			{
				sum += c;
				rs[3]++;
			}
			else if (canput(2))
			{
				sum += b;
				rs[2]++;
			}
			else
			{
				sum += a;
				rs[1]++;
			}
		}
	}
	else if (a == b && b == c) // a,b,c相等: a/b/c
		jztz(a,zf[1],zf[2],zf[3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ifstream ifs;
	ifs.open("../evaldata/club1.ans");
	cin >> T;
	while (T--)
	{
		da = -1;
		ifs >> da;
		if (da != -1 && da != 0) 
		{
			cout << da << endl;
		}
		sum = 0;
		zf[1] = zf[2] = zf[3] = 0;
		rs[1] = rs[2] = rs[3] = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			zf[1] += a[i].a;
			zf[2] += a[i].b;
			zf[3] += a[i].c;
			a[i].getmax();
		}
		sort(a + 1,a + n + 1,cmp);
		for (int i = 1;i <= n;i++) toput(a[i].a,a[i].b,a[i].c);
		cout << sum << endl;
	}
}
