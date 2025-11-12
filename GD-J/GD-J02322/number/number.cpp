#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100008],c=1;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a+1,a+c);
	for(int i=c-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
