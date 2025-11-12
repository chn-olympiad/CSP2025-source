#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m,x;
struct node
{
	int f,id;
}r[N];
bool cmp(node a,node b)
{
	return a.f>b.f;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >> m;
    int ts = n*m;
    for (int i = 1;i<=ts;i++)
    {
    	cin >> r[i].f;
    	r[i].id = i;
	}
	sort(r+1,r+ts+1,cmp);
	for (int i = 1;i<=ts;i++)
	{
		if (r[i].id == 1)
		{
			x = i;
			break;
		}
	}
	int xy = (x-1)/n+1,xx;
	if (xy%2 == 1)
	{
		xx = (x-1)%n+1;
	}
	else
	{
		xx = n-((x-1)%n+1)+1;
	}
	cout << xy << " " << xx;
	return 0;
}

