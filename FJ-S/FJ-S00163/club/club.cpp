#include <bits/stdc++.h>
using namespace std;
long long n,l,dyg,deg,dsg,num,ak;
int gtr[4];
int main(){
	freopen("club.in","r",stdin);
	long long u=0;
	cin>>n;
	cin>>l;
	for(int i=0;i<n;i++){
		num=0;
		for(int j=0;j<l;j++){
			for(int k=0;k<3;k++){
				cin>>gtr[k];
			}
			if(gtr[u]>gtr[u+1]){
				if(gtr[u]>gtr[u+2]){
					dyg++;
					num+=gtr[u];
				}
				if(gtr[u]<gtr[u+2]){
					dsg++;
					num+=gtr[u+2];	
				}
			}
			if(gtr[u]<gtr[u+1]){
				if(gtr[u+1]>gtr[u+2]){
					deg++;
					num+=gtr[u+1];					
				}
				if(gtr[u+1]<gtr[u+2]){
					dsg++;
					num+=gtr[u+2];
				}			
			}
		}
		if(dyg>n/2){
			if(gtr[u+1]>gtr[u+2]){
				deg++;
				dyg--;
				num-=gtr[u];
				num+=gtr[u+1];
			}
			if(gtr[u+1]<gtr[u+2]){
				dsg++;
				dyg--;
				num-=gtr[u];
				num+=gtr[u+2];
			}
		}
		if(deg>n/2){
			if(gtr[u+2]>gtr[u]){
				dsg++;
				deg--;
				num-=gtr[u+1];
				num+=gtr[u+2];
			}
			if(gtr[u]>gtr[u+2]){
				dyg++;
				deg--;
				num-=gtr[u+1];
				num+=gtr[u];
			}
		}
		if(dsg>n/2){
			if(gtr[u]>gtr[u+1]){
				dyg++;
				dsg--;
				num-=gtr[u+2]; 
				num+=gtr[u];
			}
			if(gtr[u]<gtr[u+1]){
				deg++;
				dsg--;
				num-=gtr[u+2];
				num+=gtr[u+1];
			}
		}
		cout<<num<<endl; 
	}
	freopen("club.out","w",stdout);
	return 0;
}
