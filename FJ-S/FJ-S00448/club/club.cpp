#include <bits/stdc++.h>
using namespace std;


/*贪心策略: 
1.优先对于每个社团分配满意度最高的人
2.还需满足这个人没有其他的最喜欢的社团 
3.重复上述过程 
*/

long long n,ans,nowa,nowb,nowc;

struct student
{
	int a,b,c;
	int belong=-1;
	int maxlike;
}member[114514];

bool cmp1(student a,student b)
{
	return a.maxlike>b.maxlike;
}

void mai()
{
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> member[i].a >> member[i].b >> member[i].c;
		member[i].maxlike=max(member[i].a,max(member[i].b,member[i].c));
	}
	
	nowa=0,nowb=0,nowc=0,ans=0;

		sort(member+1,member+n+1,cmp1);
		for (int i=1;i<=n;i++)
		{
			if (max(member[i].a,max(member[i].b,member[i].c))==member[i].a)//CLUB A
			{
				if (nowa<n/2)//happy to get A!
				{
					nowa++;
					ans+=member[i].maxlike;
					member[i].belong=1;
				}
			}
			if (max(member[i].a,max(member[i].b,member[i].c))==member[i].b)//CLUB B
			{
				if (nowb<n/2)//happy to get B!
				{
					nowb++;
					ans+=member[i].maxlike;
					member[i].belong=2;
				}
			}
			if (max(member[i].a,max(member[i].b,member[i].c))==member[i].c)//CLUB C
			{
				if (nowc<n/2)//happy to get C!
				{
					nowc++;
					ans+=member[i].maxlike;
					member[i].belong=3;
				}
			}
		}


	cout << ans << endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt;
	cin >> ttt;
	for (int hdja=1;hdja<=ttt;hdja++)mai();
	return 0;
}
