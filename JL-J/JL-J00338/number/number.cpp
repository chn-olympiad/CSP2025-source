#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	int b[1000000];
	cin>>a;
	for(int i=0;i<=strlen(a);i++){
		
		if(a[i]>='0'&&a[i]<='9') {b[j]=a[i];j++;}
	}
	for(int i=0;i<strlen(b);i++){
		for(int j=1;j<=strlen(b);j++){
		if(b[i]<b[j]) swap(b[i],b[j]);
		}
	}int c=0;
	for(int i=0;i<=strlen(b);i++){
	c=c*10+b[i]
	}
		cout<<c;
		return 0;
	}
