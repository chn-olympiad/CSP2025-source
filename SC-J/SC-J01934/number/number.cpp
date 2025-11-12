#include<bits/stdc++.h>
using namespace std;
int a[1005];
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
	int asn=s.size();
	int n=0;
	for(int i=0,j=0;i<=asn-1;i++) {
		if(s[i]<='9') {
			a[j]=s[i]-'0';
			j++;
			n++;
		}
	}
	for(int i=0;i<=n-1;i++) {
		for(int j=i+1;j<=n-1;j++) {
			if(a[i]<a[j]) {
				int g=a[i];
				a[i]=a[j];
				a[j]=g;
			}
		}
	}
	for(int i=0;i<=n-1;i++) {
		cout<<a[i];
	}
	return 0;
}