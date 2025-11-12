#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N],cnt;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i]))
			a[++cnt] = s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
} 
