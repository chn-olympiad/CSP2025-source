#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]<='9' && s[i]>='0'){
			a[++len]=s[i]-'0';
		}
	}
	sort(a+1,a+1+len);
	for(int i=len;i>=1;i--) cout<<a[i];
	return 0;
} 
