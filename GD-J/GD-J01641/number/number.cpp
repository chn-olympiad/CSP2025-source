#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],top=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		char x=s[i];
		if('0'<=x && x<='9'){
			a[top]=x-'0';
			top++;
		}
	}
	sort(&a[0],&a[top]);
	for(int i=top-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
