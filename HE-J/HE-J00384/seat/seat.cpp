#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,o,p,a[105];
bool cmp(int a1,int a2)
{
	return a1>a2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
		if(i==1) p=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			cout << x << ' ' << y;
			return 0;
		}
		if(o) {if(--y<1) o=!o,x++,y++;}
		else {if(++y>n) o=!o,x++,y--;}
	}
	return 0;
}
