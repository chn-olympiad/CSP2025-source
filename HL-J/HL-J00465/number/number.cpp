#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005],b,k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s[1]<='0'||s[1]>='0'){
		if(s[1]>s[0]){
			cout<<s[1]<<s[0];
		
		}
		else{
			cout<<s[0]<<s[1];
			
		}
	}
	else{
		cout<<s;
		
	}
	return 0;
}
