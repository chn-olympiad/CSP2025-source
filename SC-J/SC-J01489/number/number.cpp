#include<bits/stdc++.h>
#define ll long long
#define Suika 0
using namespace std;
const int N=1000010;
int a[N];
int cnt;
string s;
int t[20];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin>>s;
	int n=s.size();
	for(int i=0; i<n; i++) {
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=(int(s[i]-'0'));
	}
	for(int i=1; i<=cnt; i++) t[a[i]]++;
	for(int i=9; i>=0; i--) {
		for(int j=1; j<=t[i]; j++) cout<<i;
	}
	return Suika;
}