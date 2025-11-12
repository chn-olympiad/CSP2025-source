#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int maxn=0,n;
struct node
{
	int x=0,y=0,z=0,pos;
}a[N];
void dfs(int t,int tot,int c1,int c2,int c3)
{
	if (t>n){ maxn=max(maxn,tot); return ;}
	
	if (c1<n/2) dfs(t+1,a[t].x+tot,c1+1,c2,c3);
	if (c2<n/2) dfs(t+1,a[t].y+tot,c1,c2+1,c3);
	if (c3<n/2) dfs(t+1,a[t].z+tot,c1,c2,c3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >>T;
	while (T--)
	{
		maxn=0;
		cin >>n;
		for (int i=1;i<=n;i++)
		{
			cin >>a[i].x>>a[i].y>>a[i].z;
			a[i].pos=i;
		 } 
		dfs(1,0,0,0,0);
		cout <<maxn<<endl;
	}
	return 0;
 } //bushi，我是真不会 
 
 /*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
