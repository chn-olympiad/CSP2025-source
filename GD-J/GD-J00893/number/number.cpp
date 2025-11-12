#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]<'0' || s[i]>'9'){
			s.erase(i,1);
			i--;
		}
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s.c_str();
	return 0;
}
