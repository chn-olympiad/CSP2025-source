#include<bits/stdc++.h>
#include<string>
using namespace std;
int main() {
	int l;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[15]= {0};
	string b;
	cin>>b;
	for(int i=0; i<b.size(); i++) {
		if(b[i]>='0'&&b[i]<='9') {
			l=b[i]-'0';
			a[l]++;
		}
	}
	for(int i=9; i>=0; i--) {
		while(a[i]>0) {
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}