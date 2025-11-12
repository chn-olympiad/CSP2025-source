#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],m;
char n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		m=s[i];
		if(m>=48&&m<=57)a[m-48]++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			while(a[i]--)cout<<i;}
	}
return 0;
}
