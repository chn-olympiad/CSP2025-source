#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r".,stdin);
	//freopen("number.out","w",stdont);
	char a[30];
	char b[30];
	cin>>a;
	int c=0,p=0;
	for(int i=0;i<30;i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[c]=a[i];
			c=c+1;
		}
	}
	char d[c];
	for(int i=0;i<c;i++){
		if(b[i]=='9'){
			d[p]='9';
			p++;
			break;
		}
	}
		for(int i=0;i<c;i++){
		if(b[i]=='8'){
			d[p]='8';
			p++;
		}
	}
		for(int i=0;i<c;i++){
		if(b[i]=='7'){
			d[p]='7';
			p++;
		}
	}
		for(int i=0;i<c;i++){
		if(b[i]=='6'){
			d[p]='6';
			p++;
		}
	}
		for(int i=0;i<c;i++){
		if(b[i]=='5'){
			d[p]='5';
			p++;
		}
	}
		for(int i=0;i<c;i++){
		if(b[i]=='4'){
			d[p]='4';
			p++;
		}
	}
	for(int i=0;i<c;i++){
		if(b[i]=='3'){
			d[p]='3';
			p++;
		}
	}
	for(int i=0;i<c;i++){
		if(b[i]=='2'){
			d[p]='2';
			p++;
		}
	}
	for(int i=0;i<c;i++){
		if(b[i]=='1'){
			d[p]='1';
			p++;
		}
	}
	for(int i=0;i<c;i++){
		if(b[i]=='0'){
			d[p]='0';
			p++;
		}
	}
	cout<<d;
	return 0;
}
