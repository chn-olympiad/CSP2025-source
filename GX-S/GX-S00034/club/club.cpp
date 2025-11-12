#include<bits/stdc++.h>
using namespace std;
struct man
{
	int a;
	int b;
	int c;
};
man a[100005];
bool cmp(man x,man y)
{
	return x.a>y.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int n,s=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			s=s+a[i].a;
		cout<<s;
	}
	return 0;
}
