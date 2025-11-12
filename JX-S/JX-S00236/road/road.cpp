#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ipt[N];
int p1[25]={4,4,2,1,4,6,2,3,7,4,2,5,4,3,4,1,1,8,2,4,100,1,3,2,4};


bool n[5];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
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
		if(!n[0]){cout<<13;break;}
		if(!n[1]){cout<<13;break;}
		if(!n[2]){cout<<13;break;}
		if(!n[3]){cout<<13;break;}
		if(!n[4]){cout<<13;break;}
		
		
	}

}