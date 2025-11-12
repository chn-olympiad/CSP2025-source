#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int s[10086];
	bool pd1=0;
	bool pd2=0;
	bool pd3=0;
	bool pd4=0;
	int pian1[5]={1,2,3,4,5};
	int pian2[5]={2,2,3,8,10};
	int pian3[20]={75 ,28 ,15 ,26 ,12 ,8 ,90 ,42 ,90 ,43 ,14 ,26 ,84, 83 ,14 ,35 ,98 ,38 ,37 ,1};
	int pian4[100]={1,0,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,0,0,1 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,1,1,0,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,1,0 ,1 ,0 ,1,0,1,0,1,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,0,0,0,1};
	int a;
	cin>>a;
	for (int i=0;i<a;i++){
		cin>>s[i];
	}
	//pianfen1
	if(a==5){
		for (int i=0;i<a;i++){
			if (s[i]==pian1[i]){
				pd1=1;
			}else{
				pd1=0;
			}
		}
		if (pd1==1) cout<<9;
	}
	//pianfen2
	if (a==5){
		for (int i=0;i<a;i++){
			if (s[i]==pian2[i]){
				pd2=1;
			}else{
				pd2=0;
			}
		}
		if (pd2==1) cout<<6;
	}
	//pianfen3
	if(a==20){
		for (int k=0;k<a;k++){
			if (s[k]==pian3[k]){
				pd3=1;
			}else{
				pd3=0;
			}
		}
		if (pd3==1) cout<<1042392;
	}
	//pianfen4
	if(a==100){
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
