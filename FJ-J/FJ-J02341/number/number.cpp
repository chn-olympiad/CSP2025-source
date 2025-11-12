#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c=0,t[N];
string s;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++) {
    	if(s[i]>='0'&&s[i]<='9') {
    		int tmp=s[i]-'0';
    		t[c]=tmp;
    		c++;
		}
	}
	sort(t,t+c,greater<int>());
	for(int i=0;i<c;i++) {
		cout<<t[i];
	}
	return 0;
}
