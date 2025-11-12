#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,k,a[5005],ans,q,ma,qq,qqq,yb,sum,bj[5005];
string st;
void hx(int x,int xx)
{
	if(sum>2*ma&&x>3) ans=(ans+1)%mod;
	if(x>n) return;
	for(int i=xx+1;i<=n;i++)
	{
		if(bj[i]==0)
		{
			bj[i]=1;
			sum+=a[i];
			ma=max(ma,a[i]);
			int maa=ma;
			hx(x+1,a[i]);
			bj[i]=0;
			sum-=a[i];
			ma=maa;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	hx(1,0);
	cout<<ans%mod;
	return 0;
 } 
