#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],z;
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z=s[i]-'0';
			a[z]=a[z]+1;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	
	
	
	return 0;
}
