#include<bits/stdc++.h>
using namespace std;
bool bmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char Sr[1000001]={};
	int Kd=0;
	cin>>Sr;
	char Kr[1000001]={};
	int Dkd=0;
	for(int i=0;i<strlen(Sr);i++){
		if(Sr[i]>='0' && Sr[i]<='9'){
			Kr[Dkd]=Sr[i];
			Dkd++;
		}
	}
	sort(Kr,Kr+Dkd,bmp);
	for(int i=0;i<=Dkd;i++){
		cout<<Kr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
