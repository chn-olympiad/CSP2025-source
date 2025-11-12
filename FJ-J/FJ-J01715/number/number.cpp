#include<iostream>
using namespace std;
int main() {
	string s;
	cin>>s;
	long long a[s.size()],n=0;
	for(int i=0; i<s.size(); i++) {
		a[i]=-1;
		a[i]=0;
	}
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[i]=s[i]-'0';
			n++;
		}
	}
	int ma=0,k=0,x=0;
	for(int i=0; i<n; i++) {
		ma=0;
		for(int j=0; j<s.size(); j++) {
			if(a[j]==-1) {
				continue;
			}
			if(a[j]>=ma){
				ma=a[j];
				k=j;
			}
		}
		x=x*10+ma;
		a[k]=-1;
	}
	cout<<x;
	return 0;
}
