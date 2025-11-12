#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int n=1;
string s;
getline(cin,s); 

for(int i=0;i<s.size();i++){
	if(s[i]-'0'<=9){
		a[n]=s[i]-'0';
		n++;
	}
}
sort(a+1,a+n+1);

	for(int i=n;i>1;i--){
	cout<<a[i];
	}

return 0;
}
