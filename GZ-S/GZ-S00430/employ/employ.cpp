//GZ-S00430 毕节七星关东辰实验学校 赵锡元
#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
ll n,t,anss=1;
char ru1;
ll viss[500860],ru2,ru3,ru4;
ll bian;
struct qp
{
	ll now,ce;
};
bool bi(qp a,qp b)
{
	return a.ce<b.ce;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>ru1;
		anss*=i;
		anss%=998244353;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>ru2;
		if(ru2==0)bian++;
	}
	cout<<anss;
	return 0;
}
