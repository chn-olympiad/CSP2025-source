#include <bits/stdc++.h>
using namespace std;



int e1,e2,e3,e4,e5,e6,m1[1000000],m2,m3,t,n;
bool f = 0;
struct node
{
	int a1,a2,a3;
	int maxpos,maxnum;
}a[1000000];

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			int maxn = max(max(a[i].a1,a[i].a2),a[i].a3);
			if(maxn == a[i].a1) a[i].maxpos = 1,a[i].maxnum = a[i].a1;
			else if(maxn == a[i].a2) a[i].maxpos = 2,a[i].maxnum = a[i].a2;
			else a[i].maxpos = 3,a[i].maxnum = a[i].a3;
			if(!(a[i].a2 == a[i].a3&&a[i].a2 == 0))f = 1;
			m1[i] = a[i].a1;
		}
		sort(m1+1,m1+n+1);
		//1
		if(n == 2)
		{
			if(a[1].maxpos != a[2].maxpos)
			{
				cout << a[1].maxnum+a[2].maxnum << endl;
				
			}
			else
			{
				if(a[2].maxpos == 1)
					e1 = a[1].maxnum+max(a[2].a2,a[2].a3);
				else if(a[2].maxpos == 2)
					e2 = a[1].maxnum+max(a[2].a1,a[2].a3);
				else
					e3 = a[1].maxnum+max(a[2].a1,a[2].a2);
				int p = max(e1,max(e2,e3));
				if(a[1].maxpos == 1)
					e4 = a[2].maxnum+max(a[1].a2,a[1].a3);
				else if(a[1].maxpos == 2)
					e5 = a[2].maxnum+max(a[1].a1,a[1].a3);
				else
					e6 = a[2].maxnum+max(a[1].a1,a[1].a2);
				int p2 = max(e4,max(e5,e6));
				cout << max(p,p2) << endl;
			}
		}
		//12
		else if(!f)
		{
			for(int i = n;i > n/2;i--)
			{
				m2 += m1[i];
			}
			cout << m2 << endl;
		}
	}
	return 0;
}
