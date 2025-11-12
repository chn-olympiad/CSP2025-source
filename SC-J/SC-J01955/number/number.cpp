#include <bits/stdc++.h>
using namespace std;
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
const int N=127;
string s;
int a[N];
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/

/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
/*

*/