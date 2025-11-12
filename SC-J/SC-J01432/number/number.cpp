#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<cstring>
using namespace std;
char a[1000005];
int b[15];
char n[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(a,1000005);
	long len=strlen(a);
	long long ww=-1;
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]]+=1;
			ww++;
		}
	}
	int f=0;
	int ii=9;
	long www=ww;
	for(int i=int('9');i>=int ('0');i--){
		while(b[i]!=0){
			n[ww]=char(i);
			ww--;
			if(ww==-1){
				f=1;
				ww++;
				break;
			}
			b[i]--;
		}
		ii--;
		if(f==1){
			break;
		}
	}
	for(int i=www;i>=ww;i--){
		cout<<n[i];
	}
	return 0;
} 