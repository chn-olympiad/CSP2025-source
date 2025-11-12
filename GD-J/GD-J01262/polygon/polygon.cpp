#include<bits/stdc++.h>
using namespace std;
int a[5050];
int maxx=0,js=0,bian=3,yuan,n;
long long cnt=0,ans=0;
const long long M=998244353;
void dg(int i)
{
	if(js>=bian)
	{
		return;
	}
	for(int j=i+1;j<=n;j++)
	{
		cnt+=a[j];
		yuan=maxx;
		maxx=max(maxx,a[j]);
		js++;
		dg(j);
		if(cnt>2*maxx && js==bian)
		{
			ans++;
		}
		cnt-=a[j];
		maxx=yuan;
		js--;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(bian=3;bian<=n;bian++)
	{
		dg(0);
	}
	cout << ans%M << endl;
	return 0;
}
