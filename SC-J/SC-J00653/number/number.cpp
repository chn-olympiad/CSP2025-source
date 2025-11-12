#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	s=" "+s;
	int l=s.size()-1,cnt=1;
	for(int i=1;i<=l;i++){
		if(s[i]>='0' && s[i]<='9') a[cnt++]=(s[i]-'0');
	}
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout << a[i];
	}
    return 0;
}