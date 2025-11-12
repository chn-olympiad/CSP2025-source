#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e5 + 5;
ll n,q,c[N];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i = 1; i <= n ; i++){
		cin >> a >> b;
		c[a.size()]++;
	}
	for(int i = 1 ; i <= q ; i++){
		cin >> a >> b;
		printf("%lld",c[a.size()]);
	}
	return 0;
}
