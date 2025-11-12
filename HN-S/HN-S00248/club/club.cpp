#include <iostream>
#include <algorithm>
#include <queue>
#define kevin1616 slove();
#define AK slove2();
#define IOI slove3();
#define luogu slove4();
#define id703489 slove5();
using namespace std;
long long n,m,t,cnt[5];
string s;
struct nodes
{
	long long val,id;
	bool operator < (const nodes &w)const
	{
		return val > w.val;
	}
}h[5];
struct node
{
	nodes b[5];
	bool operator < (const node &w)const
	{
		return b[1].val - b[2].val > w.b[1].val - w.b[2].val;
	}
}a[200005];
priority_queue<node>q[5];
void slove()
{
	cin >> t;
	return ; 
}
void slove2()
{
	while(t --)
	{
		cin >> n;
		cnt[1] = 0,cnt[2] = 0,cnt[3] = 0;
		for(long long i = 1;i <= n;i ++)
		{
			for(long long j = 1;j <= 3;j ++)cin >> h[j].val,h[j].id = j;
			sort(h + 1,h + 4);
			for(long long j = 1;j <= 3;j ++)a[i].b[j] = h[j];
		}
		sort(a + 1,a + n + 1);/*
		cout << "Error\n";
		for(long long i = 1;i <= n;i ++)cout << a[i].b[1].val << " " << a[i].b[2].val << " " << a[i].b[3].val << '\n';*/
		long long sum = 0;
		for(long long i = 1;i <= n;i ++)
		{
			if(cnt[a[i].b[1].id] == n / 2)sum += a[i].b[2].val,cnt[a[i].b[2].id] ++;
			else sum += a[i].b[1].val,cnt[a[i].b[1].id] ++;
		}
		cout << sum << '\n';
	}
	return ;
}
void slove3(){return ;}
void slove4(){return ;}
void slove5(){return ;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	kevin1616 AK IOI luogu id703489
	return 0;
}
//Ren5Jie4Di4Ling5%
