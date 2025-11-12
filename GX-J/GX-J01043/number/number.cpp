#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int m=1e6+5;
string s;
ll n;
ll ans[m];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    ll cnt=0;
    if(n==1){
		cout<<s[0]-'0';
		return 0;
	}
    for(ll i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			ans[cnt]=s[i]-'0';
		}
	}
	sort(ans+1,ans+cnt+1);
	for(ll i=cnt;i>=1;i--){
		cout<<ans[i];
	}
}
