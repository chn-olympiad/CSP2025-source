#include<bits/stdc++.h>
using namespace std;
int a[10000007],al,sl;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sl=s.length();
	for(int i=0;i<=sl-1;i++) if(s[i]<='9'&&s[i]>='0') al++,a[al]=s[i]-'0';
	for(int i=1;i<=al-1;i++){
		for(int j=i+1;j<=al;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=al;i++) cout<<a[i];
	return 0;
}
