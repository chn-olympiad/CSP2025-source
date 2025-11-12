#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
const long long mod=998244353;
int n;long long f[N+5],f2[N+5],a[N+5],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;f[0]=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=N+1;j>a[i];j--) ans+=f[j],ans%=mod;
		for(int j=0;j<N+1;j++) f2[j]=f[j];
		f[N+1]*=2;
		for(int j=0;j<N+1;j++)
		{
			if(j+a[i]>N+1) f[N+1]+=f2[j],f[N+1]%=mod;
			else f[j+a[i]]+=f2[j],f[j+a[i]]%=mod;
		}
	}
	cout<<ans;
	return 0;
}
/*
froepen("number.in","r",stdin);
froepen("number.out","w",stdout);
freopem("number.in","r",stdin);
freopem("number.out","w",stdout);
上面这些东西都是用来诈骗你的 awa
unsigned long long good163的rp=-1
AK,AK,oo,oo,oo!
*/
