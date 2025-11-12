#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
}a[100001];
int sum,cnt1,cnt2,cnt3;
int main()
{
	freopen("club.in",r,stdin);
	freopen("club.out",w,stdout);
	ios::sync_with_stdio(false);
	int t,n;
	cin >>t;
	for(int i=1;i<=t;i++)
	{
		cin >>n;
		for(int j=1;j<=n;j++)
		{
			cin >>a[j].a>>a[j].b>>a[j].c;
			sum+=max(a[i].max(a[i].b,a[i].c))
		}
		cout <<sum<<' ';
	}
	return 0;
}
