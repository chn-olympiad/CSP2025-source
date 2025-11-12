#include<bits/stdc++.h>
using namespace std;
string s ;
int n , ans[1000006] , cnt ;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s ;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9')ans[++cnt]=s[i]-'0';
	}
	sort(ans+1,ans+1+cnt);
	for(int i=cnt;i>=1;i--)cout << ans[i] ;
	return 0;
}