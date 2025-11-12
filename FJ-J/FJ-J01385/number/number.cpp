#include<bits/stdc++.h>
using namespace std;
int n[1000005],m;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>=48&&s[i]<=57){
			n[m]=s[i];
			m++;
		}
	}
	sort(n,n+m);
	for(int i=m-1;i>=0;i--)cout<<char(n[i]);
	return 0;
} 
