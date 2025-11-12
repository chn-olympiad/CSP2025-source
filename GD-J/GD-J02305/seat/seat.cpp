#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n,m,r;
int a[200];
bool cmp(const int &a, const int &b)
{
	return a>b;
}
void dfs(int pos, int x, int y)
{
	if(x>n || y>m)
		return;
	if(a[pos]==r)
	{
		cout<<y<<" "<<x;
		return;
	}
	if(y%2==1)
	{
		if(x==n)
			dfs(pos+1, x, y+1);
		else
			dfs(pos+1, x+1, y);
	}
	else
	{
		if(x==1)
			dfs(pos+1, x, y+1);
		else
			dfs(pos+1, x-1, y);
	}
}
int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
			r = a[i]; 
	}
	sort(a+1, a+n*m+1, cmp);
	dfs(1, 1, 1);
	return 0;
}
