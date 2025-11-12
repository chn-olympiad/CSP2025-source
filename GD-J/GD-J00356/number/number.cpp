#include<bits/stdc++.h>
using namespace std;
string s;
int y,z,h,a[1000005],a1,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.size(),s=" "+s;
	for(int i=1;i<=n;i++) if(s[i]>='0'&&s[i]<='9') a[++a1]=s[i]-'0';
	sort(a+1,a+1+a1); 
	for(int i=a1;i>=1;i--) cout<<a[i];
	return 0;
} 
