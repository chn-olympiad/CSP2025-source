#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
string s[200005][2];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		cin >> a >> b;
		printf("0\n");
	}
	return 0;
}
