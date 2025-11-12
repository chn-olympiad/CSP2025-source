#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
void f(long long k,long long l,long long ma,long long o)
{
	if(k>n)
	{
		if(ma*2<l&&o>=3) ans++,ans%=998244353;
		return ;
	}
	f(k+1,l+a[k],max(ma,a[k]),o+1);
	f(k+1,l,ma,o);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	 {
	 	scanf("%lld",&a[i]);
     }
    f(1,0,0,0);
    cout<<ans;
	//相同为0，不同为1 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
