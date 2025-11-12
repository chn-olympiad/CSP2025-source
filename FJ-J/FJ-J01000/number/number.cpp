#include<bits/stdc++.h>
using namespace std;
long long s[1000010];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long j=1,b=1;
	cin>>a;
	for(long long i=0; i<a.size(); i++) {
		if(a[i]>='0'&&a[i]<='9') {
			s[j++]=a[i]-48;
			if(a[i]=='0') {
				b++;
			}
		}
	}
	if(b==j) {
		cout<<0;
		return 0;
	}
	j--;
	sort(s+1,s+j+1,cmp);
	for(long long i=1; i<=j; i++) {
		cout<<s[i];
	}
	return 0;
}
