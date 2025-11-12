#include<bits/stdc++.h>
using namespace std;
char a[1000010]= {};
int t[1000010];
int cnt;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0; i<l; i++) {
		a[i]=s[i];
	}
	for(int i=0; i<l; i++) {
		if(a[i]>='0'&&a[i]<='9') {
			t[cnt]=a[i]-48;
			cnt++;
		}
	}
	sort(t,t+cnt+1);
	for(int i=cnt; i>0; i--) {
		cout<<t[i];
	}
	return 0;
}