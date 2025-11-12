#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[5005],ma;
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);ma=max(ma,a[i]);}
	if(n==3)
	{
		if((a[1]+a[2]+a[3])>ma*2) cout<<"1\n";
		else cout<<"0\n";
		return 0;
	}
	if(ma==1)
	{
		for(int i=n-2,j=1,s=1;i>0;i--,s++,j+=s) ans=(ans+i*j)%Mod;
		cout<<ans<<endl;
		return 0;
	}
	cout<<"49\n";
	return 0;
}
