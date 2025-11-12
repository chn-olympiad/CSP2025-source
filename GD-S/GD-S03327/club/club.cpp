#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

struct No
{
	int l1,l2;
	int d1,d2;
}a[100005];
pair<int,int> my;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	priority_queue<pi> q1,q2,q3;
	for(int i = 1;i <= t;i++)
	{
		int n;
		cin >> n;
		for(int j = 1;j <= n;j++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			if(x == max(x,max(y,z)))
			{
				a[j].d1 = x;
				a[j].l1 = 1;
				if(y == max(y,z))
				{
					a[j].d2 = y;
					a[j].l2 = 2;
				}
				else 
				{
					a[j].d2 = z;
					a[j].l2 = 3;
				}
			}
			else if(y == max(x,max(y,z)))
			{
				a[j].d1 = y;
				a[j].l1 = 2;
				if(x == max(x,z))
				{
					a[j].d2 = x;
					a[j].l2 = 1;
				}
				else 
				{
					a[j].d2 = z;
					a[j].l2 = 3;
				}
			}
			else 
			{
				a[j].d1 = z;
				a[j].l1 = 3;
				if(y == max(y,x))
				{
					a[j].d2 = y;
					a[j].l2 = 2;
				}
				else 
				{
					a[j].d2 = x;
					a[j].l2 = 1;
				}
			}
			if(a[j].l1 == 1)
			{
				q1.push(make_pair(a[j].d2 - a[j].d1,j));
				if(q1.size() > n / 2) 
				{
					my = q1.top();
					q1.pop();
					if(a[my.second].l2 == 2) q2.push(make_pair(a[j].d2 - a[j].d1,my.second));
					else q3.push(make_pair(a[j].d2 - a[j].d1,my.second));
				}
			}
			else if(a[j].l1 == 2)
			{
				q2.push(make_pair(a[j].d2 - a[j].d1,j));
				if(q2.size() > n / 2) 
				{
					my = q2.top();
					q2.pop();
					if(a[my.second].l2 == 1) q1.push(make_pair(a[j].d2 - a[j].d1,my.second));
					else q3.push(make_pair(a[j].d2 - a[j].d1,my.second));
				}
			}  
			else
			{
				q3.push(make_pair(a[j].d2 - a[j].d1,j));
				if(q3.size() > n / 2) 
				{
					my = q3.top();
					q3.pop();
					if(a[my.second].l2 == 2) q2.push(make_pair(a[j].d2 - a[j].d1,my.second));
					else q1.push(make_pair(a[j].d2 - a[j].d1,my.second));
				}
			} 
		}
		long long sum = 0;
		while(!q1.empty())
		{
			my = q1.top();
			q1.pop();
			if(a[my.second].l1 == 1) sum += a[my.second].d1;
			else sum += a[my.second].d2;
		}
		while(!q2.empty())
		{
			my = q2.top();
			q2.pop();
			if(a[my.second].l1 == 2) sum += a[my.second].d1;
			else sum += a[my.second].d2;
		}
		while(!q3.empty())
		{
			my = q3.top();
			q3.pop();
			if(a[my.second].l1 == 3) sum += a[my.second].d1;
			else sum += a[my.second].d2;
		}
		cout << sum << endl;
	}
	return 0;
 } 
