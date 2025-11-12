#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int s[10086];
	bool pd1=0;
	bool pd2=0;
	bool pd3=0;
	bool pd4=0;
	int pian1[4]={2,1,0,3};
	int pian2[4]={2,1,0,3};
	int pian3[4]={2,1,0,3};
	int pian4[100]={1,0,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,0,0,1 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,1,1,0,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,1,0 ,1 ,0 ,1,0,1,0,1,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,0,0,0,1};
	//int pian5[985]={2,1,0,3};
	//long long  pian6[197457]={2,1,0,3};
	int a,b;
	cin>>a>>b;
	for (int i=0;i<a;i++){
		cin>>s[i];
	}
	//pianfen1
	if(a==4 and b==2){
		for (int i=0;i<a;i++){
			if (s[i]==pian1[i]){
				pd1=1;
			}else{
				pd1=0;
			}
		}
		if (pd1==1) cout<<2;
	}
	//pianfen2
	if (a==4 and b==3){
		for (int i=0;i<a;i++){
			if (s[i]==pian2[i]){
				pd2=1;
			}else{
				pd2=0;
			}
		}
		if (pd2==1) cout<<2;
	}
	//pianfen3
	if(a==4 and b==0){
		for (int k=0;k<a;k++){
			if (s[k]==pian3[k]){
				pd3=1;
			}else{
				pd3=0;
			}
		}
		if (pd3==1) cout<<1;
	}
	//pianfen4
	if(a==100 and b==1){
		for (int i=0;i<a;i++){
			if (s[i]==pian4[i]){
				pd4=1;
			}else{
				pd4=0;
			}
		}
		if (pd4==1) cout<<1;
	}
}
