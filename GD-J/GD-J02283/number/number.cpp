#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],c=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(48<=int(a[i])&&int(a[i])<=57){
			b[c]=int(a[i])-48;
			c++;
		}
	}
	sort(b,b+c);
	for(int i=c-1;i>=1;i--){
		cout<<b[i];
	}
	return 0;
} 
