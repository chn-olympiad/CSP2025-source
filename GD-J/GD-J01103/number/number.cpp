#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0';
	}
	sort(a+1,a+n+1);
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=0) {
			flag=false;
			break;
		}
	} 
	if(flag) cout<<'0';
	else for(int i=n;i>=1;i--) cout<<char(a[i]+'0');
} 
