#include <iostream>
using namespace std;
#define int long long
int a[5001],n,MOD=998244353;
int solve1(){
	int ans;
	for(int i=1;i<=n;i++){
		ans=ans*2%MOD;
	}
	int ans2=ans-1-n*(n-1)/2-n;
	if(ans2<0)ans2+=MOD;
	return ans2;
}
int solve(int x){
	int maxn=0,tot=0;
	int y=n,cnt=0;
	while(x!=0){
		if(x&1==1){
			tot+=a[y];
			maxn=max(a[y],maxn);
			cnt++;
		}
		x>>=1,y--;
	}
	//cout << x << ' ' << tot << endl;
	if(cnt<3)return 0;
	return maxn*2<tot;
}
signed main(){
	//freopen("polygon1/polygon1.in","r",stdin);
	//freopen("polygon.in","r",stdin);
	//Ðé»ÎÒ»Ç¹HHH
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag)cout << solve1();
	else{
		int ans=0;
		for(int i=1;i<(1<<n);i++){
			ans+=solve(i);
		}
		cout << ans;
	}
	return 0;
}

