#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100000+10;
string s1,s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<ll(s.size());i++){
		if(isdigit(s[i]))s1+=s[i];
	}
	sort(s1.begin(),s1.end());
	for(ll i=(s1.size()-1);i>=0;i--){
		cout<<s1[i];
	}
	return 0;
}
