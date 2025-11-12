#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+5,MOD=998244353;
ll n,a[N],cnt;
void xg(ll cur,string s){
	if(cur==n){
		ll mx=0,sum=0,x=0;
		for(int i=0;i<s.size();i++)if(s[i]-'0'==1)mx=a[i+1],sum+=a[i+1],x++;
		if(sum>mx*2&&x>=3) cnt++,cnt%=MOD;
		return ;
	}
	xg(cur+1,s+"0");
	xg(cur+1,s+"1");
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20){
		xg(0ll,"");
		cout<<cnt<<endl;
	}else if(a[n]==1){
		cnt=0;
		for(int i=3;i<=n;i++){
			ll num=1;
			for(int j=1;j<=i;j++){
				num*=(n-j+1);
				num/=j;
				num%=MOD;
			}
			cnt+=num;
			cnt%=MOD;
			
		}
		cout<<cnt<<endl;
	}else {
		cnt=0;
		for(int i=3;i<=n;i++){
			ll num=1;
			for(int j=1;j<=i;j++){
				num*=(n-j+1);
				num/=j;
				num%=MOD;
			}
			cnt+=num;
			cnt%=MOD;
			
		}
		cout<<cnt<<endl;
	}
	return 0;
}