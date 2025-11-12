#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll top=0;
	for(ll i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++top]=int(s[i])-48;
		}
	}
	sort(a+1,a+top+1);
	string number;
	for(ll i=top;i>=1;i--){
		number+=char(a[i]+48);
	}
//	cout<<top;
	cout<<number;
	return 0;
}