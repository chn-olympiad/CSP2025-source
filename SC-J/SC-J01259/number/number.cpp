#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN=1e6+10;
string s;
int x[MAXN];
int c;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=(int)s.size();i++){
		if(s[i]>'0'&&s[i]<'9'){
			x[c]=s[i]-'0';
			c++;
		}
	}
	sort(x,x+c);
	for(int i=c-1;i>=0;i--){
		cout<<x[i];
	}
	return 0;
}
