#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 500005
bool flag=1;
int n,a[N],ans;
int jc(int n){
	int cnt=1;
	for(int i=1;i<=n;++i)cnt%=M,cnt*=(i%M);
	return cnt;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ans+=a[i];
		if(a[i]!=1)flag=0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(ans>a[n]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag){
		int num=0;
		for(int i=3;i<=n;++i){
			int a=1;
			a*=jc(n)%M/jc(n-i);
			num+=a;
		}
		cout<<num;
		return 0;
	}
	return 0;
}
