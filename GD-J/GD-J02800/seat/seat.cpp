#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
int a[114514];
int n,m,i,j,k,xm,pos, lie=1;
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	memset(a,0,sizeof(a));
	m=m=i=j=k=xm=pos=0;
	lie=1;
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w",stdout);
	cin >> n >> m;
	for (i=1; i<=n*m; i++) cin >> a[i];
	xm=a[1];
	sort(a+1, a+1+n*m, cmp);
	for (i=1; i<=n*m; i++)
		if (a[i] == xm) break;
	pos =i;
	while (pos > n) pos -=n, lie++;
	if (lie & 1) cout << lie << " "<< pos;
	else cout <<  lie<< " "<< n-pos+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
