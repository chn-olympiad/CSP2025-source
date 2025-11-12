#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int _mod=998244353;
int n;
int a[5005];
int _max=0,ans=0;
void dfs(int x,int g,int e,int sum,int _max1)
{
	if (g==e){
		if (sum>_max1*2){
			ans=(ans+1)%_mod;
		}
		return;
	}
	for (int i=x+1; i<=n; i++){
		int _max2=_max1;
		if (a[i]>_max1){
			_max1=a[i];
		}
		dfs(i,g+1,e,sum+a[i],_max1);
		_max1=_max2;
	}
}
int power(int a,int b)
{
	int ans=1;
	for (; b; b>>=1){
		if (b&1){
			ans=ans*a%_mod;
		}
		a=a*a%_mod;
	}
	return ans;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=0;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		_max=max(a[i],_max);
		if (a[i]!=1){
			flag=1;
		}
	}
	if (n<=3){
		if (a[1]+a[2]+a[3]>2*_max){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if (flag==0){
		cout<<(power(2,n)%_mod-1-n-n*(n-1)/2+_mod)%_mod;
		return 0;
	}
	for (int i=3; i<=n; i++){
		for (int j=1; j<=n; j++){
			dfs(j,1,i,a[j],a[j]);
		}
	}
	cout<<ans;
	return 0;
}
