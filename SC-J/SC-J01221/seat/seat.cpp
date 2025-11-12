//普巴保佑我AC
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,pm,fs;
int d[105];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>d[i];
	fs=d[1];
	sort(d+1,d+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)
	{
//		cout<<d[i]<<' ';
		if(d[i]==fs)
		{
			pm=i;
			break;
		}
	}
//	cout<<pm<<endl;
	int l=ceil(pm*1.0/n);
	if(l&1)
		cout<<l<<' '<<pm-(l-1)*n;
	else
		cout<<l<<' '<<n-(pm-(l-1)*n)+1;
	return 0;
}