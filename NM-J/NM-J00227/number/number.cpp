#include<bits/stdc++.h>
using namespace std;
string s,a[1000];
int m=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
for(int i=0;i<=9;i++){
	if(int(s[i]-'0')<=9){
	a[m]=s[i];
	m++;
}
}
sort(a+1,a+1+m);
for(int i=m;m>1;i--){
	cout<<a[i];
	}
return 0;
}

