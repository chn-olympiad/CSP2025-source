#include<bits/stdc++.h>
using namespace std; 
string s;
char a[100005];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9') a[n++]=s[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--) cout<<a[i];
	return 0;
}
