#include <bits/stdc++.h>
using namespace std;
int b[1000005]; 
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int cnt=0;
	int len=a.size();
	for(int i=0;i<len;++i) {
		if(a[i]>='0'&&a[i]<='9') {
			b[++cnt]=a[i]-48;
		}
	} 
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;++i) {
		cout<<b[i];
	}
	return 0;
}
