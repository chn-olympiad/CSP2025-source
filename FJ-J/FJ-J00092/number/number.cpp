#include<bits/stdc++.h>
using namespace std;
char g[1000010];
string s;
long long j=0;
int main() {
	ios::sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long h=s.size();
	for(long long i=0; i<h; i++) {
		char x=s[i];
		if(x<='9'&&x>='0') {
			j++;
			g[j]=x;
		}
	}
	sort(g+1,g+j+1);
	for(long long i=j; i>=1; i--)
		cout<<g[i];
	cout<<endl;
}
