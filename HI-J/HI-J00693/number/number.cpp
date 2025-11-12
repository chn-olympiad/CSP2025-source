#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	getline(cin,b);
	int cs=0,num=0,zj;
	while(b[cs]>0){
		if(b[cs]>=48&&b[cs]<=57){
			num++;
		}
		cs++;
	}
	int xg[num]={};
	num=0;
	for(int m=0;m<cs;m++){
		if(b[m]>=48&&b[m]<=57){
			xg[num]=b[m]-48;
			num++;
		}
}
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++){
			if(xg[i]<xg[j]){
				zj=xg[i];
				xg[i]=xg[j];
				xg[j]=zj;
			}
		}
	}
	for(int i=0;i<num;i++){
		cout<<xg[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
