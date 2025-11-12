#include<bits/stdc++.h>
using namespace std;
const int MA = 1e6 + 10;
string s;
int a[MA];
bool cmp(int x,int y) {
	return x>y ;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = 0, y = s.size();
	for(int i=0; i<y; i++) {
		//cout<<s[i] - '0'<<"/n";
		if(s[i] - '0' <=9 && s[i] - '0' >= 0) {
			n++;
			a[n] = s[i] - '0';
			//cout<<a[n]<<" ";
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1; i<=n; i++) cout<<a[i];
	return 0;
}

