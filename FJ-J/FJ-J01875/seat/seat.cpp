// T2 AC
#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n,m;
vector<int> a;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m); int tmp;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d",&tmp),a.push_back(tmp);
	
	int v = a[0],id = 0;
	sort(a.begin(),a.end(),greater<int>());
	for(int i = 0; i < a.size(); i++) if(a[i] == v) { id = i + 1; break; }
	int x = 1,y = 1,f = 1;
	while(id - 1)
	{
		y += f;
		if(y > n) y = n,f = -1,x++;
		if(y < 1) y = 1,f = 1,x++;
		id--;
	}
	printf("%d %d\n",x,y);
	return 0;
}

