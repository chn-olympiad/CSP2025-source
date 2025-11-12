#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t="";
	cin>>s;
	for(ll i=0;i<ll(s.size());i++){
		if(isdigit(s[i])){
			t+=s[i];
		}
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	cout<<t;
	return 0;
}
