#include<bits/stdc++.h>
using namespace std;

struct A{
	int n, id;
};

struct E{
	A info[3];
	bool flag; 
}s[100100];

bool f1, f2, f3;
int t, n, ans, tmp;
int tot1, tot2, tot3;

void Sort(int k)
{
	
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &s[i].info[0].n, &s[i].info[1].n, &s[i].info[2].n);
			s[i].info[0].id = 1, s[i].info[1].id = 2, s[i].info[2].id = 3;
		}
		
		for(int i = 1; i <= n; i++)
		{
			Sort(i);
			if(s[i].info[0].id == 0 && tot1 <= n / 2 && !s[i].flag)
				tot1++, ans += s[i].info[0].n, s[i].flag = true;
			else if(s[i].info[0].id == 1 && tot2 <= n / 2 && !s[i].flag)
				tot2++, ans += s[i].info[0].n, s[i].flag = true;
			else if(s[i].info[0].id == 2 && tot3 <= n / 2 && !s[i].flag)
				tot3++, ans += s[i].info[0].n, s[i].flag = true;
		}
		for(int i = 1; i <= n; i++)
//			printf("%d %d %d\n", s[i].info[0].n, s[i].info[1].n, s[i].info[2].n);
		cout<<ans<<endl;
	}
	return 0;
}
