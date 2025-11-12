#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,ans,w[200005],l[200005],r[200005],tmp,tmpl,tmpr;
string s[200005][2],t[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i = 1;i <= n;i++)cin >> s[i][0] >> s[i][1];
	for(ll i = 1;i <= q;i++)cin >> t[i][0] >> t[i][1];
	if(n <= 100){
		for(ll i = 1;i <= q;i++){
			if(t[i][0].size() != t[i][1].size()){
				puts("0");
				continue;
			}
			ans = 0;
			for(ll l = 0;l <= t[i][0].size() - 1;l++){
				if(t[i][0].substr(0,l) != t[i][1].substr(0,l))continue;
				for(ll r = l;r <= t[i][0].size() - 1;r++){
					for(ll j = 1;j <= n;j++){
						if(t[i][0].substr(l,r - l + 1) == s[j][0] && t[i][1].substr(l,r - l + 1) == s[j][1] && t[i][0].substr(r + 1,t[i][0].size() - r - 1) == t[i][1].substr(r + 1,t[i][1].size() - r - 1))ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	for(ll i = 1;i <= n;i++){
		for(ll j = 0;j <= s[i][0].size() - 1;j++){
			if(s[i][0][j] == 'b'){
				l[i] = j,r[i] = s[i][0].size() - j - 1;
				break;
			}
		}
		for(ll j = 0;j <= s[i][1].size() - 1;j++){
			if(s[i][1][j] == 'b'){
				w[i] = j - l[i];
				break;
			}
		}
	}
	for(ll i = 1;i <= q;i++){
		if(t[i][0].size() != t[i][1].size()){
			puts("0");
			continue;
		}
		for(ll j = 0;j <= t[i][0].size() - 1;j++){
			if(t[i][0][j] == 'b'){
				tmpl = j,tmpr = t[i][0].size() - j - 1;
				break;
			}
		}
		for(ll j = 0;j <= s[i][1].size() - 1;j++){
			if(s[i][1][j] == 'b'){
				tmp = j - tmpl;
				break;
			}
		}
		ans = 0;
		for(ll j = 1;j <= n;j++)if(w[j] == tmp && tmpl >= l[j] && tmpr >= r[j])ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
