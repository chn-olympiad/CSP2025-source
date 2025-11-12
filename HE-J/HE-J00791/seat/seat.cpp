#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l;
	cin>>h>>l;
	int zn=h*l;
	int s[zn];
	
	for(int i=0;i<zn;i++){
		cin>>s[i];
	}int r=s[0];
	int rzb;
	for(int i=0;i<zn;i++){
		for(int j=0;j<zn;j++){
			if(s[i]>s[j]){
				swap(s[i],s[j]);
				
			}
		}		
	}
	for(int j=0;j<zn;j++){
			if(s[j]==r){
				rzb=j;				
			}
		}		
	
	int znz[h+2][l+2]={};
	for(int i=0;i<=h+1;i++){
		for(int j=0;j<=l+1;j++){
			znz[i][j]=888;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=l;j++){
			znz[i][j]=0;
		}
	}
	int i=1,j=1;
	int n=0;
	for(int zzz=0;zzz<zn;zzz++){
		if(n==0){
			if(zzz==rzb){
				cout<<j<<" "<<i;
				return 0;
			}
			znz[i][j]=999;
				i++;
			if(znz[i+1][j]!=0&&znz[i][j-1]!=0&&znz[i-1][j]!=0&&znz[i][j+1]==0){
				
				n=1;
			}
		}
		else if(n==1){
			if(zzz==rzb){
				cout<<j<<" "<<i;
				return 0;			
			}
			znz[i][j]=999;
			j++;
			
			n=2	;
		}
		else if(n==2){
			if(zzz==rzb){
				cout<<j<<" "<<i;
				return 0;				
			}
				znz[i][j]=999;
				i--;
			if(znz[i+1][j]!=0&&znz[i][j-1]!=0&&znz[i-1][j]!=0&&znz[i][j+1]==0){
				n=3;
			}		
		}
		else if(n==3){
			if(zzz==rzb){
				cout<<j<<" "<<i;
				return 0;				
			}
			znz[i][j]=999;
				j++;
			n=0;			
		}
	}	
	
	/*
2 2
98 99 100 97
	
	
	*/
	
	
	
	
	
	
	
	
	return 0;
}
