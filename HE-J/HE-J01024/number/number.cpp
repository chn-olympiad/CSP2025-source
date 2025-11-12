#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[1000001];
if(s.size()==1){
	cout<<s;
}
	for(int i = 0;i<=s.size();i++){
	a[i] = s[i];
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '9'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '8'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '7'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '6'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '5'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '4'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '3'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '2'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '1'){
	cout<<a[i];
}
}
for(int i = 0;i<=s.size();i++){
if(a[i] == '0'){
	cout<<a[i];
}
}


	
	return 0;
} 
