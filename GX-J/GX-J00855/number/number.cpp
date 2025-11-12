#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a="",sum="";
	int c[11]={};
	cin >> a;
	for(int i=0;i<a.size();i++){
		char b=a[i];
		if(b<='9'&&b>='0'){
			c[(int)b-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(c[i]--){
			if(i==9){
				sum+='9';
			}else if(i==8){
				sum+='8';
			}else if(i==7){
				sum+='7';
			}else if(i==6){
				sum+='6';
		
				sum+='5';	}else if(i==5){
			}else if(i==4){
				sum+='4';
			}else if(i==3){
				sum+='3';
			}else if(i==2){
				sum+='2';
			}else if(i==1){
				sum+='1';
			}else if(i==0){
				sum+='0';
			}
		}
	}
	cout << sum;
	return 0;
}
// 
