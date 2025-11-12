#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ll len=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9')
			a[++len] = s[i]-'0';
	} 
	sort(a+1,a+1+len);
	//cout<<len<<endl; 
	for(int i=len;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
