#include<bits/stdc++.h>
using namespace std;
int x[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(x,0,10);
	char a[1000005];
	char b[10]={'0','1','2','3','4','5','6','7','8','9'};
	cin>>a;
	int number=strlen(a);
	for(int i=0;i<number;i++){
		for(int j=0;j<10;j++){
			if(a[i]==b[j]){
				x[j]++;
			}
		}
	}
	for(int i=0;i<x[9];i++){
		cout<<9;
	}
	for(int i=0;i<x[8];i++){
		cout<<8;
	}
	for(int i=0;i<x[7];i++){
		cout<<7;
	}
	for(int i=0;i<x[6];i++){
		cout<<6;
	}
	for(int i=0;i<x[5];i++){
		cout<<5;
	}
	for(int i=0;i<x[4];i++){
		cout<<4;
	}
	for(int i=0;i<x[3];i++){
		cout<<3;
	}
	for(int i=0;i<x[2];i++){
		cout<<2;
	}
	for(int i=0;i<x[1];i++){
		cout<<1;
	}
	for(int i=0;i<x[0];i++){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
