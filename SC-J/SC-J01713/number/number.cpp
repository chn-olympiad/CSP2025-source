#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll j,a[1000005];
int main(){
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			j++;
	   	 	a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	for(ll i=j;i>=1;i--){
		cout<<a[i];
	}
	
	
	return 0;
} 