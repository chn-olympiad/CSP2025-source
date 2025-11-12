#include<bits/stdc++.h>
using namespace std;
string s;int a[1000001];int k;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=1;i<=s.size();i++){
	if(s[i-1]>='0'&&s[i-1]<='9'){
		a[k]=s[i-1]-'0';k++;}}
sort(a,a+k);
for(int i=k-1;i>=0;i--){
	cout<<a[i];}
return 0;}