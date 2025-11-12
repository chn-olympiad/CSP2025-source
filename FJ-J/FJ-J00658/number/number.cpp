#include<bits/stdc++.h>
using namespace std;
string s;
int a[1100000],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++len]=s[i]-48;
		}
	}
	sort(a+1,a+1+len);
	for(int i=len;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
