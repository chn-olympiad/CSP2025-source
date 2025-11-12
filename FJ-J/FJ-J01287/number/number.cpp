#include<bits/stdc++.h>
using namespace std;
char c[1000100];
int mp[15];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c;
	int n=strlen(c);
	for(int i=0; i<n; ++i) {
		int x=c[i]-'0';
		if(x>=0&&x<=9) mp[x]++;
	}
	for(int i=9; i>=0; --i)
		while(mp[i]--) cout<<i;
}
