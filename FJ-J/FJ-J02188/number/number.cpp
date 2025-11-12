#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=s.size()-1;
	for(int i=0; i<=len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[++cnt]=s[i]-48;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1; i<=cnt; i++) {
		if(a[1]!=0) {
			cout<<a[i];
		} else {
			cout<<0;
			break;
		}
	}
	return 0;

}

