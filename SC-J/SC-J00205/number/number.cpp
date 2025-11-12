#include<bits/stdc++.h>
using namespace std;
char a;
int nu[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
			if(a=='0'){
				nu[0]++;
			}
			else if(a=='1'){
				nu[1]++;
			}
			else if(a=='2'){
				nu[2]++;
			}
			else if(a=='3'){
				nu[3]++;
			}
			else if(a=='4'){
				nu[4]++;
			}
			else if(a=='5'){
				nu[5]++;
			}
			else if(a=='6'){
				nu[6]++;
			}
			else if(a=='7'){
				nu[7]++;
			}
			else if(a=='8'){
				nu[8]++;
			}
			else if(a=='9'){
				nu[9]++;
			}
	}
	for(int i=1;i<nu[9]+1;i++){
		cout<<9;
	}
	for(int i=1;i<nu[8]+1;i++){
		cout<<8;
	}
	for(int i=1;i<nu[7]+1;i++){
		cout<<7;
	}
	for(int i=1;i<nu[6]+1;i++){
		cout<<6;
	}
	for(int i=1;i<nu[5]+1;i++){
		cout<<5;
	}
	for(int i=1;i<nu[4]+1;i++){
		cout<<4;
	}
	for(int i=1;i<nu[3]+1;i++){
		cout<<3;
	}
	for(int i=1;i<nu[2]+1;i++){
		cout<<2;
	}
	for(int i=1;i<nu[1]+1;i++){
		cout<<1;
	}
	for(int i=1;i<nu[0]+1;i++){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}