#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],z=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i]-'0';
			++z;
		}
	}
	for(int i=0;i<z;++i){
		for(int j=0;j<z;++j){
			if(a[j]<=a[j+1]){
				a[j]^=a[j+1];
				a[j+1]^=a[j];
				a[j]^=a[j+1];
			}
		}	
	}
	for(int i=0;i<z-1;++i){
		cout<<a[i];
	}
	return 0;
} 
