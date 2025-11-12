#include <bits/stdc++.h>
using namespace std;
const int N=105;
struct stu
{
	int p,id;
}a[N];
bool cmp(stu a,stu b)
{
	return a.p>b.p;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt++;
			cin>>a[cnt].p;
			a[cnt].id=(i-1)*j+j;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int pm=0;
	for(int i=1;i<=cnt;i++)
	{
		if(a[i].id==1) 
		{
			pm=i;
			break;
		}
	}
	int l=(pm-1)/n+1;
	cout<<l<<" ";
	int qm=(l-1)*n;
	int ld=pm-qm;
	if(l&1) cout<<ld;
	else cout<<n-ld+1; 	
	return 0;
}