#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll t=0;
	for(ll i=0;i<ll(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+t,cmp);
	for(ll i=1;i<=t;i++)printf("%lld",a[i]);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
