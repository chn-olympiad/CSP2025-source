#include <bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+5;
long long a[N],maxn=-1,b[N],n=0;
char c[N];
inline  pai(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x='0',y='9';
	for(int i=1; i<=s.size(); i++) {
		c[i]=s[i-1];
		if((c[i]-48>=0)&&(c[i]-48<=9)) {
			a[i]=c[i]-48;
			n++;
		}
	}
	sort(a,a+n+1);
	for(int i=n; i>0; i--)
		cout<<a[i];
	return 0;
}


