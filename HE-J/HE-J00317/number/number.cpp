#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(ll i=0;i<s.length();i++){
		if(s[i]>=48&&s[i]<=57)a[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(ll j=0;j<a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
