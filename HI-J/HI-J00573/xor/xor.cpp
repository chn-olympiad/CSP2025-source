#include<bits/stdc++.h>
using namespace std;
int a[100000];
int c[100000];
int main(){
	int x,y,cnp=1,o=0;
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	for(int i=1;i<=x;i++){
		c[i]=0;
	}
	for(int i=1;i<=x;i++){
		while(a[i]!=0){
			c[i]+=a[i]%2;
			c[i]*=10;
			a[i]/=2;
		}
	}
	for(int i=1;i<=x;i++){
		for(int j=1+i;i<=x;i++){
			int s+=c[i]+c[j];
			int oo=s;
			int er=2;
			while true{
				int xx=1;
				while (oo!=0){
					cnp*10;
					oo=oo/10;
					er=er*2;
				}
				int yy=s/cnp;
				if((yy%xx)%2!=0){
					o+=(s/cnp);
				}
				o=o*10;
				cnp=cnp/10;
				x=x*10;
			}
			while true{
				
			}		
		}
	}
	return 0;
} 
