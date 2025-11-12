#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin>>s;
	for(int i=0;i<(int)(s.size());i++) {
	    if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';	
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<a[i];
    return 0;	
}
