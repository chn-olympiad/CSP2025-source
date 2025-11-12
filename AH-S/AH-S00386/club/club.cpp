#include<bits/stdc++.h>
using namespace std;
int t, n;
struct stu
{
	int p[3];
	void read(){cin >> p[0] >> p[1] >> p[2];}
	void print(){cout << p[0] << '\t' << p[1]<< '\t' << p[2] << '\n';}
};
bool comp1(stu st1, stu st2){return st1.p[0] > st2.p[0];}
bool comp2(stu st1, stu st2){return st1.p[1] > st2.p[1];}
bool comp3(stu st1, stu st2){return st1.p[2] > st2.p[2];}
inline int STmax(stu st){return max(max(st.p[0], st.p[1]), st.p[2]);}
int ans, res, cnt[3];
stu a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;ans = 0;
		if(n < 30)
		{
			int c;
			unsigned long long max_C = 1;
			for(int i = 1; i <= n; i++)
				a[i].read(), max_C *= 3;
			for(unsigned long long Choice = 1; Choice < max_C; Choice++)
			{
				cnt[0] = cnt[1] = cnt[2] = 0;
				int temp = Choice;	res = 0;
				for(int i = 1; i <= n; i++)
				{
					c = temp % 3, temp /= 3;
					if(cnt[c] < n / 2)
						res += a[i].p[c], cnt[c]++;
					else goto next;
				}
				if(res > ans)
					ans = res;
				next:;
			}
			cout << ans << "\n";
		}
		else
		{
			for(int i = 1; i <= n; i++)a[i].read();
			if(a[1].p[2] == 0)
			{
				sort(a + 1, a + 1 + n, comp1);
				if(a[1].p[1] == 0)//A
				{
					for(int i = 1; i <= n / 2; i++)
						ans += a[i].p[0];
				}
				else//B
				{
					cnt[0] = cnt[1] = 0;
					for(int i = 1; i <= n; i++)
						if(a[i].p[0] > a[i].p[1] && cnt[0] < n / 2)
							ans += a[i].p[0], cnt[0]++;
						else
							ans += a[i].p[1];
					
				}
			}
			else
				for(int i = 1; i <= n; i++)
					ans += STmax(a[i]);
		}
		cout << ans << "\n";
	}
}
