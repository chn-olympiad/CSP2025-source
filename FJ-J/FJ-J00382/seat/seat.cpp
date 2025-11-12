#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1010],pos,line,ist;
bool flag[1010];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++) cin>>a[i];
	flag[a[1]] = 1;
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(flag[a[i]])
		{
			pos = i;
			break;
		}
	}
	ist = pos/m+1;
	if(pos%m == 0) ist--;
	line = pos%n;
	if(line == 0) line = n;
	if(ist%2 == 1) cout<<ist<<" "<<line;
	else cout<<ist<<" "<<n-line+1;
	return 0;
}
/*
1 8 9	16
2 7 10	15
3 6 11	14
4 5 12	13


*/
