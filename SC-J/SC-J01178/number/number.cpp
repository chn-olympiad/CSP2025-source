#include<bits/stdc++.h>
using namespace std;
int a[1000005],t;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0') a[++t]=s[i]-'0'; 
	}
	sort(a+1,a+t+1);
	for(int i=t;i>0;i--){
		cout<<a[i];
	}
	
	return 0;
}