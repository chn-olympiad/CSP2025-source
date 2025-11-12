#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5,MOD=998244353;
int n,a[N],SUM[N],ans;
int qpow(int a,int b)
{
	if(b==0)return 1;
	if(b==1)return a;
	int it=qpow(a,b/2);
	if(b%2)return it*it%MOD*a%MOD;
	else return it*it%MOD;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	SUM[0]=1;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int v=0;v<=a[i];v++)sum=(sum+SUM[v])%MOD;
//		cout<<sum<<"\n";
		ans=(ans+qpow(2,i-1)-sum+MOD)%MOD;
		for(int v=5000-a[i];v>=0;v--)SUM[v+a[i]]=(SUM[v+a[i]]+SUM[v])%MOD;
	}
	cout<<ans;
	return 0;
 } 
/*
5
2 2 3 8 10
*/