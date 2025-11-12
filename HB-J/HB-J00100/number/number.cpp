#include<bits/stdc++.h>
using namespace std;
string s;
int a[10086];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<int(s.length());i++){
	if(s[i]>=int('0')&&s[i]<=int('9')){
		int c=s[i]-'0';
		a[c]++;
		}
}
for(int i=9;i>=0;i--){
	for(int j=1;j<=a[i];j++)cout<<i;
}return 0;
}
