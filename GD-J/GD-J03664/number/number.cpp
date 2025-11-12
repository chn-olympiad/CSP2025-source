#include<bits/stdc++.h>
using namespace std;
long long a[10000001],g;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++g]=s[i]-48;
		}
	}
	sort(a+1,a+1+g);
	for(long long i=g;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
