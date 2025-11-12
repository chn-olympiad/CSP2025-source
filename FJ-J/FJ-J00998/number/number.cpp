#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int a[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=1;
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0' && s[i]<='9') {
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j);
	for(int i=j-1; i>=1; i--) cout<<a[i];
	return 0;
}
