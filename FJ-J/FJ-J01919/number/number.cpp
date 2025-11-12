#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b) {
	return a>b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int a[1000010],n=1;
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[n] = (int)s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n,cmp);
	if(a[0]=0) {
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<n;i++) cout<<a[i];
	
	return 0; 
}
