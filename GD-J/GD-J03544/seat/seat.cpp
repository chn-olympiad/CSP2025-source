#include<bits/stdc++.h>
using namespace std;
int n, m, f;
int s[110];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> s[i];
	}
	f=s[1];
	sort(s+1,s+1+(n*m),cmp);
	int x=1, y=1, r=1;
	for(int i=1;i<=n*m;i++)
	{
		if(s[i] == f) break;
		if(r)x++;
		else x--;
		if(x>n) y++, x-=1, r=0;
		if(x<1) y++, x+=1, r=1;
	}
	cout << y << ' ' << x;
	return 0;
}
