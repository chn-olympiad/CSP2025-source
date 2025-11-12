#include<bits/stdc++.h> 
using namespace std;
int n,m,my[100000];
int xz,x1,x2,x0,cy[10000][3],cy1[10000][3],qwertyuiop=0,pp[10000][3],jz[1000];
int pd0(){
	int dy=x0-2/n;
	for(int i=0;i<x0;i++) jz[i]=cy[i][0];
	sort(jz,jz+x0);
	for(int i=0;i<dy;i++){
		
	}
	for(int i=0;i<1000;i++) jz[i]=0;
}
int pd1(){
	int dy=x0-2/n;
	for(int i=0;i<x0;i++) jz[i]=cy[i][0];
	sort(jz,jz+x0);
	for(int i=0;i<dy;i++){
		
	}
	for(int i=0;i<1000;i++) jz[i]=0;
}
int pd2(){
	int dy=x0-2/n;
	for(int i=0;i<x0;i++) jz[i]=cy[i][0];
	sort(jz,jz+x0);
	for(int i=0;i<dy;i++){
		
	}
	for(int i=0;i<1000;i++) jz[i]=0;
}
void pd(){
	if(x0 > 2/n || x1 > 2/n || x2 > 2/n){
		if(x0 > 2/n && x1 > 2/n && x2 > 2/n){
			pd0();
			pd1();
			pd2();
		}
		else if(x0 <= 2/n){
			if( x1 > 2/n && x2 > 2/n){
				pd1();
				pd2();
			} 	
			else if( x1 > 2/n ) pd1();
			else if( x2 > 2/n ) pd2();	
		}
		else if(x1 <= 2/n){
			if( x0 > 2/n && x2 > 2/n){
				pd0();
				pd2();
			} 	
			else if( x0 > 2/n ) pd0();
			else if( x2 > 2/n ) pd2();	
		}
		else if(x2 <= 2/n){
			if( x1 > 2/n && x0 > 2/n){
				pd0();
				pd1();
			} 	
			else if( x1 > 2/n ) pd1();
			else if( x0 > 2/n ) pd0();	
		}
		
	}
	else my[qwertyuiop]=xz;	
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		x0=0;
		x1=0;
		x2=0;
		xz=0;
		cin>>m; 
		for(int j=0;j<m;j++){
			cin>>cy[j][0]>>cy[j][1]>>cy[j][2];
			if(cy[j][0]>=cy[j][1] && cy[j][0]>=cy[j][2]){
				pp[j][0]=1-1;
				if(cy[j][1]>=cy[j][2]){
					pp[j][1]=2-1;
					pp[j][2]=3-1;
				}
				else{
					pp[j][1]=3;
					pp[j][2]=2;
				}
				xz+=cy[j][pp[j][0]];
				x0++;
			}
			else if(cy[j][0]<cy[j][1] && cy[j][1]>cy[j][2]){
				pp[j][0]=2-1;
				if(cy[j][0]>=cy[j][2]){
					pp[j][1]=1-1;
					pp[j][2]=3-1;
				}
				else{
					pp[j][1]=3;
					pp[j][2]=1;
				}
				xz+=cy[j][pp[j][0]];
				x1++;
			}
			else if(cy[j][2]>cy[j][0] && cy[j][2]>cy[j][1]){
				pp[j][0]=3-1;
				if(cy[j][1]>=cy[j][2]){
					pp[j][1]=1-1;
					pp[j][2]=2-1;
				}
				else{
					pp[j][1]=2;
					pp[j][2]=1;
				}
				xz+=cy[j][pp[j][0]];
				x2++;
			}
		} 
		pd();
	} 
	cout<<my[0];
}

