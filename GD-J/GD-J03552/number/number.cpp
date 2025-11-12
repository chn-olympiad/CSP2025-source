#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
string s;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(rint i=0;i<s.size();++i) if('0'<=s[i]&&s[i]<='9') a[(int)(s[i]-'0')]++;
	for(rint i=9;i>=0;--i) while(a[i]--) cout<<i;
	return 0;
}
