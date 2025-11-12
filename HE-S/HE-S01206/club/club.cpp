#include <bits/stdc++.h>
using namespace std;
int n,sum1,sum2,sum3,num1,num2,num3;
int t;
struct ren
{
	int club1,club2,club3;
}a[100005];
bool cmp(ren a,ren b)
{
	return a.club1>b.club1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		sum1=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].club1>>a[i].club2>>a[i].club3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		{
			sum1+=a[i].club1;
		}
		cout<<sum1<<endl;
	}
	return 0;
}
