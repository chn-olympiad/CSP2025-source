#include<bits/stdc++.h>
using namespace std;
string s,a;
int b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i < s.size();i++){
		if(48 <= int(s[i]) and int(s[i])<= 57){
			a+=s[i];
		}
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	cout<<a;
	return 0;
}
