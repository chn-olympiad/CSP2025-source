
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+9;

int T , n;

struct person
{
	int id , a , b , c , val;
}p[N];

int mx (int x ,  int y , int z)
{
	return max(max(x,y),z);
}

bool cmp(person x , person y)
{
	return x.val > y.val;
}

struct nw
{
	int idx , v;
	friend bool operator<(const nw &x , const nw &y)
	{
		return x.v < y.v;
	};
};

priority_queue<nw> q;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		long long res = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> p[i].a >> p[i].b >> p[i].c;
			p[i].id = i,p[i].val = (max(max(p[i].a+p[i].b,p[i].b+p[i].c),p[i].a+p[i].c))+(min(min(p[i].a+p[i].b,p[i].b+p[i].c),p[i].a+p[i].c))-(p[i].a+p[i].b+p[i].c);
			p[i].val = max(max(p[i].a,p[i].b),p[i].c)-p[i].val;
			//cout << p[i].val << endl;
		}
		sort(p+1,p+1+n,cmp);
		//for (int i = 1;i <= n;i++)cout << p[i].id << ' ';
		//cout << endl;
		int tot[5] = {0} , flag = 0;
		for (int i = 1;i <= n;i++)
		{
			if (p[i].a >= p[i].b && p[i].a >= p[i].c && tot[1] < n/2)
			{
				tot[1]++;
			}
			else if (p[i].b >= p[i].a && p[i].b >= p[i].c && tot[2] < n/2)
			{
				tot[2]++;
			}
			else if (tot[3] < n/2)
			{
				tot[3]++;
			}
			if (tot[1] == n/2)
			{
				flag = 1;
				break;
			}
			if (tot[2] == n/2)
			{
				flag = 2;
				break;
			}
			if (tot[3] == n/2)
			{
				flag = 3;
				break;
			}
		}
		tot[1] = 0;
		tot[2] = 0;
		tot[3] = 0;
		for (int i = 1;i <= n;i++){
			if (p[i].a >= p[i].b && p[i].a >= p[i].c)
			{
				if (flag == 1 && tot[1] < n/2)
				{
					tot[1]++;
					q.push(nw{p[i].id , p[i].val});
					res += p[i].a;
				}
				else if (flag == 1)
				{
					if (p[i].val > q.top().v)
					{
						res += p[i].a-q.top().v;
						q.pop();
						q.push(nw{p[i].id , p[i].val});
					}
					else res += p[i].a - p[i].val;
				}
				else res += p[i].a;
			}
			else if (p[i].b >= p[i].a && p[i].b >= p[i].c)
			{
				if (flag == 2 && tot[2] < n/2)
				{
					tot[2]++;
					res += p[i].b;
					q.push(nw{p[i].id , p[i].val});
				}
				else if (flag == 2)
				{
					if (p[i].val > q.top().v)
					{
						res += p[i].b-q.top().v;
						q.pop();
						q.push(nw{p[i].id , p[i].val});
					}
					else res += p[i].b - p[i].val;
				}
				else res += p[i].b;
			}
			else
			{
				if (flag == 3 && tot[3] < n/2)
				{
					tot[3]++;
					res += p[i].c;
					q.push(nw{p[i].id , p[i].val});
				}
				else if (flag == 3)
				{
					if (p[i].val > q.top().v)
					{
						res += p[i].c-q.top().v;
						q.pop();
						q.push(nw{p[i].id , p[i].val});
					}
					else res += p[i].c - p[i].val;
				}
				else res += p[i].c;
			}
			
		}
		cout << res << endl;
		while(!q.empty())q.pop();
	}
	return 0;
}
