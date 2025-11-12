#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
string s;
int a[N],k=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	next_setpumusition();
	int l=s.size();
	for(int i = 0; i<l; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	for(int i = k; i>=1; i--) {
		cout<<a[i];
	}
	return 0;
}
