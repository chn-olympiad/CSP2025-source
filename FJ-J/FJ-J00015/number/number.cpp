#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000005];
int k=0;
bool cmp(int x,int y) {
	if(x > y) {
		return true;
	} else if(x < y) {
		return false;
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.size();
	for(int i=0; i<len; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			k++;
		}
	}
	sort(a+0,a+0+len,cmp);
	if(a[0] == 0) {
		cout<<0;
		return 0;
	}
	for(int i=0; i<k; i++) {
		cout<<a[i];
	}
	return 0;
}
