#include <algorithm>
#include <iostream>
#define debug false

using namespace std;

const int N = 4*114514;

int n;

struct node
{
	int a,b,c;//喜爱程度,谁,哪个社团 
}person[N];

struct node2
{
	int love[4];
}person2[N];

bool cmp(const struct node &t1,const struct node &t2)
{
	return t1.a > t2.a;
}

int flag[N];//是否有被分配进社团 

int backup_flag[N];

int cnt[5];//每个社团中的人数 

int T;

int ans = 0;

void init()
{
	for (int i = 0 ; i <= (n + 3) ; i ++) flag[i] = false;
	for (int i = 0 ; i <= 4 ; i ++) cnt[i] = 0;
	ans = 0;
}

void dfs(int x,int now)
{
	if (x > n + 1) return;
	//std :: cout << x << " " << now << "\n";
	if (x == n + 1)
	{
		//std :: cout << ans << "\n";
		ans = std :: max(ans,now);
		return;
	}
	for (int i = 1 ; i <= 3 ; i ++)
	{
		if (cnt[i] + 1 > (n / 2)) continue;
		cnt[i] ++;
		dfs(x + 1,now + person2[x].love[i]);
		cnt[i] --;
	}
}

void solve()
{
	init();
	std :: cin >> n;
	int ccnt = 0;
	for (int i = 1 ; i <= n ; i ++)
	{
		for (int j = 1 ; j <= 3 ; j ++)
		{
			ccnt ++;
			std :: cin >> person[ccnt].a;
			person[ccnt].b = i;
			person[ccnt].c = j;
			person2[i].love[j] = person[ccnt].a;
		}
	}
	if (n <= 10)
	{
		dfs(1,0);
		std :: cout << ans << "\n";
		return;
	}
	sort(person + 1,person + 1 + ccnt,cmp);
	//std :: cout << "\n";
	int l = 1,r = 1;
	int cnt_person = 0;
	int now = 0;
	int ans = 0;
	while (l <= ccnt && r <= ccnt)
	{
		int np = person[r].b;
		if (!flag[np])//这个人还没有分配 
		{
			if (cnt[person[r].c] < (n / 2))//分配进社团 
			{
				flag[np] ++;
				cnt_person ++;
				//std :: cout << "分配:" << np << "->" << person[r].c << "\n";
				//happy[np] = person[r].a;
				cnt[person[r].c] ++;
				now += person[r].a;
			}
			else//无法分配,尝试端点 
			{
				int backup_l = l;
				int backup_cnt[5];
				for (int i = 1 ; i <= 5 ; i ++)
				{
					backup_cnt[i] = cnt[i];
				}
				for (int i = 1 ; i <= (n + 3); i ++)
				{
					backup_flag[i] = flag[i];
				}
				int backup_now = now;
				int backup_cntperson = cnt_person;
				int loss = 0;//为了满足这个人需求损失的快乐值 
				int t = 0;
				#if debug
				std :: cout << "now_flag:\n";
				for (int i = 1 ; i <= n ; i ++)
				{
					std :: cout << flag[i] << " ";
				}
				std :: cout << "\n";
				#endif
				while (true)
				{
					//std :: cout << l << " " << r << "\n";
					flag[person[l].b] --;//这个人只能放弃这个社团 
					cnt_person --;
					now -= person[l].a;
					//t += person[l].a;
					loss += person[l].a;//损失了快乐值 
					cnt[person[l].c] --;
					l ++;
					if (!flag[person[l].b] && cnt[person[l].c] < (n / 2))//继续为这个人分配社团 
					{
						flag[person[l].b] ++;
						now += person[l].a;
						t += person[l].a;
						cnt[person[l].c] ++;
						loss -= person[l].a;
						cnt_person ++;
					}
					if (cnt[person[r].c] < (n / 2))//可以分配了 
					{
						//std :: cout << "loss:" << loss << " " << person[r].a << "\n";
						if (loss > person[r].a)//得不偿失
						{
							//std :: cout << "giveup\n";
							//std :: cout << now << "\n";
							//now += loss;
							//std :: cout << now << "\n";
							//now -= t;
							//std :: cout << "t:" << t << "\n";
							l = backup_l;//还不如不调整
							now = backup_now;
							for (int i = 1 ; i <= 5 ; i ++)
							{
								cnt[i] = backup_cnt[i];
							}
							for (int i = 1 ; i <= (n + 3); i ++)
							{
								flag[i] = backup_flag[i];
							}
							cnt_person = backup_cntperson;
							break; 
				 		} 
				 		//std :: cout << "分配:" << person[r].b << "->" << person[r].c << "\n";
				 		//std :: cout << "ok\n";
						flag[np] ++;
						cnt_person ++;
						cnt[person[r].c] ++;
						now += person[r].a;
						break;
					}
				}
			}
		}
		if (cnt_person == n)//每个人都找到了自己的社团
		{
			//std :: cout << "max:" << l << " " << r << "\n";
			#if debug
			std :: cout << "nowflag:\n";
			for (int i = 1 ; i <= n ; i ++)
			{
				std :: cout << flag[i] << " ";
			}
			std :: cout << "\n";
			#endif
			ans = std :: max(ans,now);
		} 
		r ++;//扩大端点 
	}
	std :: cout << ans << "\n";
}

int main()
{
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std :: cin >> T;
	while (T --) solve();
}
