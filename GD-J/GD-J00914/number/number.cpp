#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6;
string s;
ll a[N+5],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<(ll)s.size();i++){
		if(s[i]>='0' && s[i]<='9') a[++cnt]=(ll)(s[i]-'0');
	}
	sort(a+1,a+cnt+1);
	for(ll i=cnt;i>=1;i--) printf("%lld",a[i]);
	return 0;
}
