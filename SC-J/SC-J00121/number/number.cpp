#include<bits/stdc++.h>
using namespace std;
int vui=0;
char a[1000005],b[1000005];
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin.getline(b,1000003);
	if(strlen(b)<=100000){
		for(int i=0;i<strlen(b);i++){
			if(b[i]>='0'&&b[i]<='9'){
				a[++vui]=b[i];
			}
		}
		sort(a+1,a+vui+1);
		for(int i=vui;i>=1;i--) printf("%c",a[i]);
	}
	else{
		sort(b,b+strlen(b)-1+1);
		for(int i=strlen(b)-1;i>=0;i--){
			if(b[i]!='0'&&b[i]!='1'&&b[i]!='2'&&b[i]!='3'&&b[i]!='4'&&b[i]!='5'&&b[i]!='6'&&b[i]!='7'&&b[i]!='8'&&b[i]!='9') continue;
			printf("%c",b[i]);
		}
	}
	return 0;
}