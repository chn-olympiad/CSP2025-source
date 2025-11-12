#include<bits/stdc++.h>
using namespace std;
char a[1000000 + 10];
int b[1000000 + 10];
bool Fun(int a,int b){
	return a > b;
}
int main(void){
	/**/freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	int c= strlen(a);
	for(int i = 0;i < c;i++){
		if(a[i] == '0'){
			b[i] = 0;
		}else if(a[i] == '2'){
			b[i] = 2;
		}else if(a[i] == '3'){
			b[i] = 3;
		}else if(a[i] == '4'){
			b[i] = 4;
		}else if(a[i] == '5'){
			b[i] = 5;
		}else if(a[i] == '6'){
			b[i] = 6;
		}else if(a[i] == '7'){
			b[i] = 7;
		}else if(a[i] == '1'){
			b[i] = 1;
		}else if(a[i] == '8'){
			b[i] = 8;
		}else if(a[i] == '9'){
			b[i] = 9;
		}else{
			b[i] = -1;
		}
	}
	sort(b,b + strlen(a),Fun);
	for(int i = 0;i < c;i++){
		if(b[i] != -1){
			printf("%d",b[i]);
		}
	}
	
	return 0;
}
