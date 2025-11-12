#include<bits/stdc++.h>
using namespace std;
string a;
int d[1000010],f;
bool cmp(int n,int m) {
	return n>m;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int s=a.size();
	for(int i=0; i<s; i++) {
		if(a[i]>='0'&&a[i]<='9') {
			d[f++]=a[i]-'0';
		}
	}
	sort(d,d+f,cmp);
	for(int i=0; i<f; i++) {
		printf("%d",d[i]);
	}
	return 0;
}
