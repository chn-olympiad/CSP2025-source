#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,id;
};
node q[10005];
bool cmp(node a,node b)
{
	return a.val > b.val;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c = 0,r = 1,val = 1;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> q[i].val;
		q[i].id = i;
	}
	sort(q + 1,q + n * m + 1,cmp);
	for(int i = 1; i <= n * m; i++)
	{
		c += val;
		if(c > n)
		{
			c = n;
			r++;
			val = -1;
		 } 
		if(c == 0) 
		{
			c = 1;
			r++;
			val = 1;
		}
		if(q[i].id == 1)
		{
			cout << r << ' ' << c;
			break;
		}
	}
	return 0;
}
