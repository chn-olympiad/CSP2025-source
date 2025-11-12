#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct pl
{
	long long a,b,c;
	bool f=0;
};
pl pls[100100];
pl tmp;
long long n,ans,cntc;
bool cmp(pl a,pl b)
{
	if(a.f!=b.f) return a.f<b.f;
	return (a.a+b.b)<=(a.b+b.a);
}
int run()
{
	ans=0;
	cin >>n;
	cntc=n/2;
	for(int i=0;i<n;i++) cin >>pls[i].a>>pls[i].b>>pls[i].c;
	for(auto i=0;(i<n and cntc>=0);i++)
	{
		if((pls[i].c)>=(pls[i].b) and (pls[i].c)>=(pls[i].a))
		{
			ans+=(pls[i].c);
			cntc--;
			pls[i].f=1;
		}
	}
	sort(pls,pls+n,cmp);
	int i;
	for(i=0;i<n/2;i++)
	{
		if(pls[i].a<pls[i].b) break;
		ans+=pls[i].a;
	}
	for(;i<n;i++)
	{
		if(pls[i].f) break;
		ans+=pls[i].b;
	}
	cout <<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		run();
	}
}
