#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a[1000];
	for(int i=0;i<=s.size()-1;i++){
		if( s[i]>=48 && s[i]<=58 ){
			a[i]=s[i]-48;
		}
		else i+=1;
	}
	sort(a+0,a+s.size());
    //sort(a+s.size(),a+0);
	for(int i=s.size()-1;i>=0;i--){
		if( a[i]>=0 && a[i]<=9 ){
			cout<<a[i];
		}
	}
	return 0；
} 
