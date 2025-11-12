#include<bits/stdc++.h>
using namespace std;
int a[1000001],cnt,len;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=int(s.size());
	for(int i=0;i<len;i++) if(s[i]>='0' && s[i]<='9') a[++cnt]=int(s[i]-'0');
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}
