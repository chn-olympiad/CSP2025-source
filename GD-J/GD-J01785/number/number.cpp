#include<bits/stdc++.h>
using namespace std;
int a[1000010],cnt;
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[++cnt]=(int)(s[i]-'0');
		}
	}
	stable_sort(a+1,a+cnt+1);
	for(int i=cnt; i>=1; i--) {
		cout<<a[i];
	}
	return 0;
}
