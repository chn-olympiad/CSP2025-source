#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000009];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int num=0;
getline(cin,s);
for(int i=0;i<s.size();i++){
	if(s[i]>='0'&&s[i]<='9'){
	a[num]=s[i]-'0';	
		num++;
}	
}
sort(a,a+num);
for(int i=num-1;i>=0;i--){
	cout<<a[i];
}
	return 0;
}

