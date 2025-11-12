#include <iostream>
#include <cstdlib>
#include <queue>

#define int long long
#define mk_pr(x, y) std::make_pair(x, y)

const int MAXN = 1e5 + 7;

struct SF
{
    int sat1, sat2, sat3;
} members[MAXN];

int T;
int n;

int solve()
{
	int a_cnt = 0, b_cnt = 0, c_cnt = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> p1;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> p2;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> p3;
	
	for (int i = 1; i <= n; i++)
	{
		SF sf = members[i];
		if (sf.sat1 >= sf.sat2 && sf.sat1 >= sf.sat3)
		{
			if (a_cnt >= (n >> 1))
			{
				std::pair<int, int> t = p1.top();
				// std::cout << t.second << std::endl;
				if (members[t.second].sat2 + sf.sat1 > t.first + sf.sat2)
				{
					// std::cout << "Turn " << i << ' ' << t.second << " 2" << std::endl;
					p1.pop();
					p1.push(std::make_pair(sf.sat1, i));
					p2.push(t);
				}
				else if (members[t.second].sat3 + sf.sat1 > t.first + sf.sat3)
				{
					// std::cout << "Turn " << i << ' ' << t.second << " 3" << std::endl; 
					p1.pop();
					p1.push(mk_pr(sf.sat1, i));
					p3.push(t);
				}
				else
				{
					if (sf.sat2 > sf.sat3) p2.push(mk_pr(sf.sat2, i));
					else p3.push(mk_pr(sf.sat3, i));
				}
			}
			else
			{
				// std::cout << i << ' ' << " Pushed a" << std::endl;
				p1.push(mk_pr(sf.sat1, i));
				a_cnt++;
			}
		}
		else if (sf.sat2 >= sf.sat1 && sf.sat2 >= sf.sat3)
		{
			if (b_cnt >= (n >> 1))
			{
				std::pair<int, int> top = p2.top();
				if (members[top.second].sat1 + sf.sat2 > top.first + sf.sat1)
				{
					// std::cout << "Turn " << i << ' ' << top.second << " 1" << std::endl; 
					p2.pop();
					p2.push(mk_pr(sf.sat2, i));
					p1.push(top);
				}
				else if (members[top.second].sat3 + sf.sat2 > top.first + sf.sat3)
				{
					// std::cout << "Turn " << i << ' ' << top.second << " 3" << std::endl; 
					p2.pop();
					p2.push(mk_pr(sf.sat2, i));
					p3.push(top);
				}
				else
				{
					if (sf.sat1 > sf.sat3) p1.push(mk_pr(sf.sat1, i));
					else p3.push(mk_pr(sf.sat3, i));
				}
			}
			else
			{
				// std::cout << i << ' ' << " Pushed b" << std::endl;
				p2.push(mk_pr(sf.sat2, i));
				b_cnt++;
			} 
		}
		else if (sf.sat3 >= sf.sat1 && sf.sat3 >= sf.sat2)
		{
			if (c_cnt >= (n >> 1))
			{
				std::pair<int, int> top = p3.top();
				if (members[top.second].sat1 + sf.sat3 > top.first + sf.sat1)
				{
					// std::cout << "Turn " << i << ' ' << top.second << " 1" << std::endl; 
					p3.pop();
					p3.push(mk_pr(sf.sat3, i));
					p1.push(top);
				}
				else if (members[top.second].sat2 + sf.sat3 > top.first + sf.sat2)
				{
					// std::cout << "Turn " << i << ' ' << top.second << " 2" << std::endl; 
					p3.pop();
					p3.push(mk_pr(sf.sat3, i));
					p2.push(top);
				}
				else
				{
					if (sf.sat1 > sf.sat2) p1.push(mk_pr(sf.sat1, i));
					else p2.push(mk_pr(sf.sat2, i));
				}
			}
			else
			{
				// std::cout << i << ' ' << " Pushed c" << std::endl;
				p3.push(mk_pr(sf.sat3, i));
				c_cnt++;
			}
		}
	}
	
	int ans = 0;
	while (!p1.empty())
	{
		ans += p1.top().first;
		p1.pop();
	}
	while (!p2.empty())
	{
		ans += p2.top().first;
		p2.pop();
	}
	while (!p3.empty())
	{
		ans += p3.top().first;
		p3.pop();
	}
	
	return ans;
}

signed main()
{
    freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;

    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> members[i].sat1 >> members[i].sat2 >> members[i].sat3;
        }
        
        std::cout << solve() << std::endl;
    }
}
