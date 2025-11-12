#include<iostream>
#include<algorithm>
#include<cstring>
using std::cin;
using std::cout;
using std::max;
using std::min;
using std::sort;

int n,cnt[4],mx;

struct Student{
	int a,b,c;
	inline int get_max(){
		return max(a,max(b,c));
	}
	inline int get_mid(){
		return a + b + c - max(a,max(b,c)) - min(a,min(b,c));
	}
	inline int group(){
		if(a >= b && a >= c)
		{
			return 1;
		}
		else if(b >= a && b >= c)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
}stu[100005],g[4][100005];

bool cmp1(Student s1,Student s2){
	return s1.get_max() > s2.get_max();
}

bool cmp2(Student s1,Student s2){
	if(mx == 1)
	{
		return max(s1.b,s1.c) - s1.a > max(s2.b,s2.c) - s2.a;
	}
	if(mx == 2)
	{
		return max(s1.a,s1.c) - s1.b > max(s2.a,s2.c) - s2.b;
	}
	return max(s1.a,s1.b) - s1.c > max(s2.a,s2.b) - s2.c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long ans = 0;
		memset(cnt,0,sizeof(cnt));
		memset(stu,0,sizeof(stu));
		memset(g,0,sizeof(g));
		cin>>n;
		for(int i = 1;i <= n;i += 1)
		{
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
		}
		sort(stu + 1,stu + 1 + n,cmp1);
		for(int i = 1;i <= n;i += 1)
		{
			cnt[stu[i].group()] += 1;
			g[stu[i].group()][cnt[stu[i].group()]] = stu[i];
		}
		if(cnt[1] > cnt[2] && cnt[1] > cnt[3])
		{
			mx = 1;
		}
		else if(cnt[2] > cnt[1] && cnt[2] > cnt[3])
		{
			mx = 2;
		}
		else
		{
			mx = 3;
		}
		sort(g[mx] + 1,g[mx] + 1 + cnt[mx],cmp2);
		for(int i = 1;i <= cnt[mx] - (n >> 1);i += 1)
		{
			ans += g[mx][i].get_mid();
		}
		for(int i = 1;i <= 3;i += 1)
		{
			if(i == mx)
			{
				for(int j = max(cnt[mx] - (n >> 1) + 1,1);j <= cnt[i];j += 1)
				{
					if(i == 1)
					{
						ans += g[i][j].a;
					}
					else if(i == 2)
					{
						ans += g[i][j].b;
					}
					else
					{
						ans += g[i][j].c;
					}
				}
			}
			else
			{
				for(int j = 1;j <= cnt[i];j += 1)
				{
					if(i == 1)
					{
						ans += g[i][j].a;
					}
					else if(i == 2)
					{
						ans += g[i][j].b;
					}
					else
					{
						ans += g[i][j].c;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
