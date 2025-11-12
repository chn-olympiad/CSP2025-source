#include <bits/stdc++.h>
using namespace std;
int a[121];
int n,m;//flt
bool cmp(int a,int b)
{
	if (a > b)return 1;
	else return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int sr = a[0];
	sort(a,a+n*m,cmp);
	cout << int(find(a,a+n*m,sr)-a) / n+1 << " " << int(find(a,a+n*m,sr)-a) % m+1;
	return 0;
}
