#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
char b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		b[i]=a[i];
		if(b[i]=='0'){
			a0++;
		}if(b[i]=='1'){
			a1++;
		}if(b[i]=='2'){
			a2++;
		}if(b[i]=='3'){
			a3++;
		}if(b[i]=='4'){
			a4++;
		}if(b[i]=='5'){
			a5++;
		}if(b[i]=='6'){
			a6++;
		}if(b[i]=='7'){
			a7++;
		}if(b[i]=='8'){
			a8++;
		}if(b[i]=='9'){
			a9++;
		}
	}
	for(int i=0;i<a9;i++){
		cout<<9;
	}
	for(int i=0;i<a8;i++){
		cout<<8;
	}
	for(int i=0;i<a7;i++){
		cout<<7;
	}
	for(int i=0;i<a6;i++){
		cout<<6;
	}
	for(int i=0;i<a5;i++){
		cout<<5;
	}
	for(int i=0;i<a4;i++){
		cout<<4;
	}
	for(int i=0;i<a3;i++){
		cout<<3;
	}
	for(int i=0;i<a2;i++){
		cout<<2;
	}
	for(int i=0;i<a1;i++){
		cout<<1;
	}
	for(int i=0;i<a0;i++){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}