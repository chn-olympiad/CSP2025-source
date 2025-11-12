#include<bits/stdc++.h>
using namespace std;
char a[100005];
int main(){
	string s;
 	int cnt=0;
 	cin>>s;
 	for(int i=0;i<s.size();i++){
 		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' ){
 			a[cnt]=s[i];
 			cnt++;
		 }
	 }
	 sort(a,a+cnt+1);
	 for(int i=0;i<cnt;i++){
	 	cout<<a[cnt-i];
	 }
	 return 0; 
}
