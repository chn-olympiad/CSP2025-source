#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,num;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(isdigit(s[i])){
			num+=s[i];
		}
	}
	sort(num.begin(),num.end());
	reverse(num.begin(),num.end());
	cout<<num;
	return 0;
}
