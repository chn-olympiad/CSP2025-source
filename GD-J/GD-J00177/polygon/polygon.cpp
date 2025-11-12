#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum;
vector<int>p;
bool ch()
{
	int max=0,te=0;
	for(int i=0;i<p.size();i++)
	{
		if(p[i]>max) max=p[i];
		te+=p[i];
	}
	return te>max*2;
}
void fu(int t,int s)
{
	for(int i=t;i<=n;i++)
	{
		p.push_back(a[i]);
		if(ch()&&s>=3) sum++;
		for(int j=i+1;j<=n;j++) fu(j,s+1);
		p.empty();s=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n);
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	fu(1,1);
	cout<<sum%998224353;
	return 0;
}
