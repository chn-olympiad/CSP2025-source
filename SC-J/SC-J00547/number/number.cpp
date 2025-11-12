#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";
	cin>>s;
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--) ans+=char(i+'0');
	}
	cout<<ans;
	return 0;
} 