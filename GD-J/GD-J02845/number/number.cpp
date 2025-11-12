#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll a[N]={},top=0;
void solve(){
	char c;
	while(cin>>c)
		if(c>='0'&&c<='9')
			a[++top]=c-'0';
	sort(a+1,a+1+top);
	for(ll i=top;i>=1;i--) cout<<a[i];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	return 0;
}
