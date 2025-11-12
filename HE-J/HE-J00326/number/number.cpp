#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=0,c=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i]-48;
			b++;
		}
	}
	sort(a,a+s.length());
	for(int i=s.length();i>=0;i--){
		if(a[i]!=0){
			c=true;
		}
		if(c&&b>0){
			cout<<a[i];
			b--;
		}
	}
	return 0;
}
