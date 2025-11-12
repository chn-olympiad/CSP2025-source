#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
vector<ll> ve;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9')ve.push_back(int(s[i])-int('0'));
	}
	sort(ve.begin(),ve.end(),cmp);
	for(auto i:ve)cout << i;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
