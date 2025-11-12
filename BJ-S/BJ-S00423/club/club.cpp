#include <bits/stdc++.h>
#define int long long
using namespace std;

int T;
int n;
struct node
{
	int a;
	int b;
	int c;
	int id;
}a[100005],ia[100005],ib[100005],ic[100005];

bool cmp1(node x,node y)
{
	return max(x.c,x.b) > max(y.c,y.b);
}
bool cmp2(node x,node y)
{
	return max(x.c,x.a) > max(y.c,y.a);
}
bool cmp3(node x,node y)
{
	return max(x.b,x.a) > max(y.b,y.a);
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	while(T--)
	{
		memset(ia,0,sizeof(ia));
		memset(ib,0,sizeof(ib));
		memset(ic,0,sizeof(ic));
		memset(a,0,sizeof(a));
		
		cin >> n;
		for(int i = 1;i <= n;i++)
			cin >> a[i].a >> a[i].b >> a[i].c;
		int pa,pb,pc;
		int ans1,ans2,ans3;
		int ca,cb,cc;
		pa = pb = pc = ans1 = ans2 = ans3 = ca = cb = cc = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i].a >= a[i].b && a[i].a >= a[i].c)
			{
				pa++;				
				ans1 += a[i].a;
				ia[pa].a = a[i].a;
				ia[pa].id = i;
				
				//ia[i].a = a[i].a;
				ia[pa].b = a[i].b - a[i].a;
				ia[pa].c = a[i].c - a[i].a;
			}
			else if(a[i].b >= a[i].a && a[i].b >= a[i].c)
			{
				pb++;
				ans2 += a[i].b;
				ib[pb].b = a[i].b;
				ib[pb].a = a[i].a - a[i].b;
				ib[pb].c = a[i].c - a[i].b;
				ib[pb].id = i;
			}
			else if(a[i].c >= a[i].a && a[i].c >= a[i].b)
			{
				pc++;
				ans3 += a[i].c;
				ic[pc].c = a[i].c;
				ic[pc].a = a[i].a - a[i].c;
				ic[pc].b = a[i].b - a[i].c;
				ic[pc].id = i;
			}
		}
		
		int nw = n / 2;
		int ans = ans1 + ans2 + ans3;
//		cout << pa << " " << pb << " " << pc << "\n";
		if(pa > nw)
		{
			//case1
			sort(ia + 1,ia + pa + 1,cmp1);
			int cnt = 0;
			while(pa > nw)
			{
				++cnt;
				ans += max(ia[cnt].b,ia[cnt].c);
				//cnt++;
				pa--;
			}
		}
		else if(pb > nw)
		{
			//case2
			sort(ib + 1,ib + pb + 1,cmp2);
			int cnt = 0;
			while(pb > nw)
			{
				++cnt;
				ans += max(ib[cnt].a,ib[cnt].c);
				pb--;
			}
		}
		else if(pc > nw)
		{
			sort(ic + 1,ic + pc + 1,cmp3);
			int cnt = 0;
			while(pc > nw)
			{
				++cnt;
				ans += max(ic[cnt].a,ic[cnt].b);
				pc--;
			}		
		}
		cout << ans << "\n";
	}
	return 0;
}
