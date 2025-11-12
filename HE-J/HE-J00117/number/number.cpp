#include <bits/stdc++.h>
using namespace std;
string s,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}
	}
    for(int i=0;i<s.length();i++){
    	for(int j=i+1;j<s.length();j++){
    		if(a[i]<a[j]){
    			swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<s.length();i++){
		cout<<a[i];
	}
	return 0;
} 
