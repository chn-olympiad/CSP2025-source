#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector <int> a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') {
            a.push_back(int(s[i]-'0'));
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	bool f=0;
	for(int i=0;i<a.size();i++){
        cout<<a[i];
	}
    return 0;
}
