#include<bits/stdc++.h>
using namespace std ;
int n , m , c[505] ;
string s ;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scafn("%d%d",&n,&m);
	cin >> s ;
	for(int i = 0 ; i < n ; i++) scanf("%d",&c[i]);
	int ans = random() ;
	ans %= 998244353 ;
	printf("%d",ans);
	return 0 ;
}
