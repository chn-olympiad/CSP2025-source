#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[l++]=s[i]-'0';
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
