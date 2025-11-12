#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
	string s;
	cin>>s;
	string b;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b.push_back(s[i]);
		}
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	cout<<b;
    return 0;
}
