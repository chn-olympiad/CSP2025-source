#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	string s;
	int c=1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[c]=s[i]-48;
			c++;
		}
	}
	sort(a,a+c);
	for(int i=c-1;i>=1;i--){
		cout<<a[i];
	}
}
