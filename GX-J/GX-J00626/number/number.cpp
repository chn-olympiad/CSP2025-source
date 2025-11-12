#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll maxn = 1e8+10;
char a[maxn];
ll s[maxn];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> a;
	ll al =  strlen(a),sl = 0;
	for(ll i = 0;i < al;i++){
		if(a[i] >='0' && a[i] <= '9'){
			s[++sl] = a[i]-'0';
		}
	}
	sort(s+1,s+sl+1);
	for(ll i = sl;i >= 1;i--){
		printf("%lld",s[i]);
		if(i==1) printf("\n");
	}
	return 0;
}
