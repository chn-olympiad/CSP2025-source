#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int n,bz[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=strlen(a);
	for(int i=0; i<n; i++) {
		if(a[i]>='0' and a[i]<='9') bz[int(a[i])]++;
	}
	for(int i=57; i>=48; i--) {
		while(bz[i]--) cout<<char(i);
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4
