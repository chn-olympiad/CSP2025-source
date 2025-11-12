#include<bits/stdc++.h>
using namespace std;
int a[1000010],l;
bool cmp(int x,int y) {
	return x>y;
}
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[i]=s[i]-'0';
			l++;
		}
	}
	sort(a+0,a+s.size(),cmp);
	for(int i=0; i<l; i++) {
		cout<<a[i];
	}
	return 0;
}
