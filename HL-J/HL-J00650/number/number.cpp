#include <bits/stdc++.h>
using namespace std;
	string s;
	char a[100010],x;
	int n=0;
int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	cin>>s;
 	for(int i=0;i<=s.size();i++){
 		if(s[i]>='0' && s[i]<='9'){
 		a[n]=s[i];
 		n++;
	   } 
	 }
	for(int i=0;i<=n;i++) {
		if(a[i]<a[i+1]){
			x=a[i];
		a[i]=a[i+1];
		a[i+1]=x;
	  }
	 }
	 for(int i=0;i<=n;i++){
	 	cout<<a[i];
	 }
	 return 0;
 }
