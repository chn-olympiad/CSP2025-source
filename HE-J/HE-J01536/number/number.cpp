#include<Bits/stdc++.h>
using namespace std;
int s;
int cmp(int a,int b) {
	return a>b;
}
int a[100005];
int j=1;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s) {
		a[j]=s;
		j++;
	}
	sort(a+1,a+1+j,cmp);
	for(int i=1; i<j; i++) {
		cout<<a[i];
	}
	return 0;
}
