/*

*/
#include<bits/stdc++.h>
using namespace std;
string a;
long long  s[10000000],t,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			s[++t]=a[i]-'0';
		}
	}
	sort(s+1,s+t+1);
	if(t<18){
		for(int i=t;i>=1;i--){
			b+=s[i]*pow(10,i-1);
		}
		cout<<b;
	}else{
		for(int i=t;i>=1;i--){
			cout<<s[i];
		}
	}
	
	return 0;
}
