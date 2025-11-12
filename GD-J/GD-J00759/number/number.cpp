#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ll a[100005];
	string s;
	cin>>s;
	ll cnt=0;
    for(int i=0;i<s.length();i++){
    	if(s[i]>=48 and s[i]<=57){
    		a[cnt]=s[i]-48;
    		cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
    	cout<<a[i];
	}
	
	return 0;
}//a 97 65 49 57
