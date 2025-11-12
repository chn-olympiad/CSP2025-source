#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int lens, lennum;
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]>='0' && s[i]<='9') a[++lennum]=s[i]-'0';
	}
	sort(a+1, a+1+lennum);
	for(int i=lennum;i>=1;i--) cout<<a[i];
	
	
	return 0;
}
