#include<bits/stdc++.h>
using namespace std;
int n,t;
int l,b,z,k,u,g;
int c=0;
int lbj[3];
int main(){
	fleopen("club.in","r","stdin");
	fleopen("club.out","w","stdout");
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>l>>b>>z;
			lbj[1]=0;
			lbj[2]=0;
			lbj[3]=0;
			if(l>b&&l>z){
				lbj[1]++;
				if(lbj[1]>n/2){
					if(b>z){
						k=k+b;
					}
					else{
						k=k+z;
					}
				}
				else{
					k=k+l;
				}
			}
			if(b>l&&b>z){
				lbj[2]++;
				if(lbj[2]>n/2){
					if(l>z){
						k=k+l;
					}
					else{
						k=k+z;
					}
				}
				else{
					k=k+b;
				}
			}
			if(z>l&&z>b){
				lbj[3]++;
				if(lbj[3]>n/2){
					if(l>b){
						k=k+l;
					}
					else{
						k=k+b;
					}
				}
				else{
					k=k+z;
				}
			}
		}
		cout<<k<<endl;
		k=0;
	}
	return 0;
}