#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct stu
{
	int mark,id;
}a[101];
bool cmp(stu a,stu b)
{
	return a.mark>b.mark;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("saet.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].mark;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int d;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			d=i;
			break;
		}
	}
	int ans1,ans2;
	ans1=(d-1)/n+1;
	int tmp=(d-1)%n+1;
	if(ans1%2==0)
	{
		ans2=n+1-tmp;
	}
	else
	{
		ans2=tmp;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
