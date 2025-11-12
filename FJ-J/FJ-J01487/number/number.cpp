#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b,c[1000005],e[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);  
	
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>=48&&s[i]<=57){
			b++;
			a[b]=s[i]-'0';
		}
	}
	sort(a+1,a+1+b);
	for(int i=1;i<=b;i++){
		e[i]=a[b+1-i];
		cout<<e[i];
	}
	
	return 0;
} 
