#include<bits/stdc++.h>
using namespace std;
//ji de shan zu shi;
const int N=1e6+50;
int n,m;
char s[600],c[600];
//ji de shan zu shi;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ji de shan zu shi;
	ios::sync_with_stdio(0);
	cin>>n>>m;
	long long ansn=1,ansm=1;
	for(int i=1;i<=n;i++)
	{
		ansn+=i*ansn;
	}
	for(int i=1;i<=m;i++)
	{
		ansm+=i*ansm;
	}
	cout<<(ansn*(ansn-ansm)%998244353)/ansm;
	//ji de shan zu shi;
	return 0;
}
