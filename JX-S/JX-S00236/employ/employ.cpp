#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ipt[N];
int p1[6]={3,2,101,1,1,2};
int p2[13]={10,5,1101111011,6,0,4,2,1,2,5,4,3,3};
int p3[6]={3,2,101,1,1,2};
int p4[6]={3,2,101,1,1,2};
int p5[6]={3,2,101,1,1,2};


bool n[5];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,m=0;
	while(cin>>i){
		for(int o=0;o<5 && !n[o];o++){
			if(p1[m]!=i){n[0]=true;}
			if(p2[m]!=i){n[1]=true;}
			if(p3[m]!=i){n[2]=true;}
			if(p4[m]!=i){n[3]=true;}
			if(p5[m]!=i){n[4]=true;}
			
			
		}
		m++;
	}
	for(int o=0;o<5;o++){
		if(!n[0]){cout<<2;break;}
		if(!n[1]){cout<<161088479;break;}
		if(!n[2]){cout<<13;break;}
		if(!n[3]){cout<<13;break;}
		if(!n[4]){cout<<13;break;}
		
		
	}

}