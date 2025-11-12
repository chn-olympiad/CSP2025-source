#include<bits/stdc++.h>
using namespace std;
string s;int b[1000005];
int a[1000005];
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a;int len=0;
	cin >> a;int b1=a;
	while(a>0){
		a/=10;
		len++;
	}
	int g=10;
	for(int i=1;i<=len;i++){
		b[i]=b1%10;
		b1/=10;
	}
	sort(b+1,b+len+1);
	for(int i=len;i>=1;i--){
		cout << b[i];
	}
	return 0;
} 
