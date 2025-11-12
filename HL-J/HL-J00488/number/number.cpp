#include<bits/stdc++.h>
#include<string>
using namespace std;
string a;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<a.size();i++){
		if(a[i]>=1&&a[i]<=9){
			s[i]=a[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]<s[i+1]){
			s[i]=s[i+1];
			s[i+1]=s[i];
		}
	}
	for(int i=0;i<s.size();i++){
		cout<<s[i];
	}
	return 0;
}