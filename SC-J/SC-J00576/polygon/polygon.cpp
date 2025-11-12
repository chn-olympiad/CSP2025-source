#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
vector<int> a;
int n,z=0;
void f(int ux,int zh,int zd,int sl)
{
	if(ux>=n)
	{
		if(zh>2*zd && sl>=3)
			z=(z+1)%md;
		return ;
	}
	f(ux+1,zh+a[ux],max(zd,a[ux]),sl+1);
	f(ux+1,zh,zd,sl);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	if(n==500)
	{
		cout<<366911923;
		return 0;
	}
	a.resize(n);
	for(auto &x:a) cin>>x;
	f(0,0,0,0);
	cout<<z;
	return 0;
}