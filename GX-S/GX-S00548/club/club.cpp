#include<bits/stdc++.h>
using namespace std; 
int c[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,b;
	cin >> t; 
	for(int x=1;x<=t;x++){
		b=0;
		int p;   
		cin >> p;
		int max=p/2+1;
		int z=0;
		c[1]=0;c[2]=0;c[3]=0;
		while(b<p){
			int m[4],n[4],f,sf,lf;
			for(int k=1;k<=3;k++){
				cin >> m[k];
				n[k]=m[k];
			}
			sort(n+1,n+4);
			for(int k=1;k<=3;k++){
				if(m[k]==n[3]) f=k;
				if(m[k]==n[2]) sf=k;
			}
			if(c[f]<max){
				c[f]+=1;
				z+=m[f];
			}
			else if(c[f]>=max){
				if(c[sf]<max){
					c[sf]+=1;
					z+=m[sf];
				}
				else{
					lf=6-f-sf; 
					if(c[lf]<max){
						c[lf]+=1;
						z+=m[lf];
					} 
				}
			}
			b+=1;
		}
		cout << z << endl;
	}
	return 0;
}
