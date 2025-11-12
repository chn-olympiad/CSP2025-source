#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int b[10001];	
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
    vector<int>a;
     for(int i=0;i<s.length();i++){
     	if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
     	   a.push_back(s[i]);
		 }
	 }
	 for(int i=0;i<a.size();i++){
	 	b[i]=a[i];
	 }
	 sort(b,b+a.size(),cmp);
	 for(int i=0;i<a.size();i++){
	 	cout<<b[i]-'0';
	 }
	return 0;
} 
