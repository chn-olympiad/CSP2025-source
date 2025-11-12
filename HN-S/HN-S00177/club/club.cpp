#include<bits/stdc++.h>
using namespace std; 
int a;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>a;
/*	while(a--){
		int n,b[10001][4],allmax=0,cbc[4],sco=0,signedd[10001]={};
		cin>>n;
		double d=n/2;
		for(int j=1;j<=d;j++){for(int k=0;k<3;k++){cbc[k]=j;}}
		for(int k=0;k<n;k++)for(int j=0;j<3;j++){cin>>b[k][j];}
		for(int k=0;k<3;k++){
			for(int i=0;i<n;i++){int tmp=0,tmp1=0;
				signedd[i]+=k;if(signedd[i]>2){signedd[i]=2;tmp1++;}
				for(int j=0;j<n;j++){
					tmp+=b[j][signedd[i]];	
				}
				if(tmp<=allmax){signedd[i]-=k;if(tmp1==1)signedd[i]++;}
				else {
					cbc[k]--;
					if(cbc[k]<0){
						int amin=100000,signz;
						for(int z=0;z<n;z++){
							if(b[z][signedd[k]]<amin){b[z][signedd[k]]=amin;signz=z;}
						}b[signz][k]=0;cbc[k]++;
					}allmax=tmp;
				}
				
				
				
				
				
			}
		}cout<<allmax<<endl;
		
		
	}*/
	for(int i=0;i<a;i++){
		int n,b[10001][4],allmax=0,cbc[4],sco=0;
		cin>>n;
		double d=n/2;
		for(int j=1;j<=d;j++){for(int k=0;k<3;k++){cbc[k]=j;}}
		
		
		for(int k=0;k<n;k++)for(int j=0;j<3;j++){cin>>b[k][j];if(b[k][j]>=allmax)allmax=b[k][j];}
		
		
		for(int l=0;l<n;l++){
			for(int j=0;j<n;j++){
				for(int k=0;k<3;k++){   
					if(b[j][k]==allmax&&cbc[k]>0){sco+=b[j][k];b[j][0]=-1;b[j][1]=-1;b[j][2]=-1;cbc[k]--;}
				}
			}allmax=0;
			for(int k=0;k<n;k++)for(int j=0;j<3;j++){if(b[k][j]>=allmax)allmax=b[k][j];}
		}cout<<sco<<endl;
		
		
	}return 0;
}
