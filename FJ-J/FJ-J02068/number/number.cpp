#include<bits/stdc++.h>
using namespace std;
char ch;
int a[11];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch) {
		if(ch-48<=9&&ch-48>=0)a[ch-48]++;
	}
	int i=10;
	while(i--) {
		while(a[i]!=0) {
			a[i]--;
			printf("%d",i);
		}
	}
	return 0;
}

