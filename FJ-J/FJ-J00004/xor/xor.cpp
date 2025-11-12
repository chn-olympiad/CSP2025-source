#include<bits/stdc++.h>
using namespace std;
int g8[917813];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int b,a;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>g8[i];
	}if(b==1){
		int ji=0;
		for(int i=1;i<=a;i++){
			if(g8[i]==1)ji++;
		}cout<<ji;return 0;
	}if(b==0){
		int ji=0,combo=0;
		for(int i=1;i<=a;i++){
			if(g8[i]==1){
				combo++;
			}else{
				ji++;
				ji+=combo/2;
				combo=0; 
			}
		}cout<<ji;return 0;
	}
}
