#include<bits/stdc++.h>
using namespace std;
char s;
//char a[1000005];
int a[1005];
int m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=8;i++){
		a[i]=49;
	}
	for(int i=1;i<=10;i++){
		cin>>s;
		m=s-'0';
		if(m<=9) a[i]=m;
	}
	sort(a+1,a+8+1);
	for(int i=8;i>=1;i--){
		if(a[i]<49)
		cout<<a[i];
	}
	return 0; 
} 
