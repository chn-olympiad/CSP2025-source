#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int jsq=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++jsq]=s[i]-'0';
		}
	}
	sort(a+1,a+1+jsq);
	for(int i=jsq;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
