#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;int a[100000];int b=0;
	cin>>s;
	for(int i=0;i<sizeof(s);i++){
	if(s[i]>='0'&&s[i]<='9'){
	a[b]=s[i]-'0';b++;}
	else{continue;}}
	sort(a,a+b+1);
	for(int i=b;i>0;i--)cout<<a[i];
	return 0;
}//123456789 123456789
