#include<bits/stdc++.h>
using namespace std;
struct sx{
	int d,z,x,y,e,s;
	int ss;
}cy[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int a=0,b=0,c=0,sum=0;
		for(int j=1;j<=n;j++){
		cin>>cy[j].y>>cy[j].e>>cy[j].s;
		if(cy[j].y>=cy[j].e&&cy[j].y>=cy[j].s){
			cy[j].d=1;
			if(cy[j].e>=cy[j].s){
				cy[j].z=2;
				cy[j].x=3;
			}
			else{
				cy[j].z=3;
				cy[j].x=2; 
			}
		}
		else if(cy[j].e>cy[j].y&&cy[j].e>=cy[j].s){
			cy[j].d=2;
			if(cy[j].y>=cy[j].s){
				cy[j].z=1;
				cy[j].x=3;
			}
			else{
				cy[j].z=3;
				cy[j].x=1; 
			}
		}
		else if(cy[j].s>cy[j].y&&cy[j].s>=cy[j].e){
			cy[j].d=3;
			
			if(cy[j].y>=cy[j].e){
				cy[j].z=1;
				cy[j].x=2;
			}
			else{
				cy[j].z=2;
				cy[j].x=1; 
			}
		}
		if(cy[j].d==1&&cy[j].z==2){
				cy[j].ss=cy[j].y-cy[j].e;
			}
			else if(cy[j].d==1&&cy[j].z==3){
				cy[j].ss=cy[j].y-cy[j].s;
			}
			else if(cy[j].d==2&&cy[j].z==1){
				cy[j].ss=cy[j].e-cy[j].y;
			}
			else if(cy[j].d==3&&cy[j].z==1){
				cy[j].ss=cy[j].s-cy[j].y;
			}
			else if(cy[j].d==3&&cy[j].z==2){
				cy[j].ss=cy[j].s-cy[j].e;
			}
			else if(cy[j].d==2&&cy[j].z==3){
				cy[j].ss=cy[j].e-cy[j].s;
			}
			
	    }
	    for(int j=1;j<=n;j++){
	        if(cy[j].d==1){
	        	sum+=cy[j].y;
	        	a++;
			}
			else if(cy[j].d==2){
	        	sum+=cy[j].e;
	        	b++;
			}
			else if(cy[j].d==3){
				sum+=cy[j].s;
	        	c++;
			}
	    }
	    if(n/2<a){
	    	for(int j=1;j<=a-n/2;j++){
	    		int sszx=999999,zxcy;
	            for(int k=1;k<=n;k++){
	            	if(cy[k].d==1&&cy[k].ss<=sszx){
	            	zxcy=k;
	            	sszx=cy[k].ss;
				}
				}
				sum-=cy[zxcy].ss;
				cy[zxcy].ss=9999999;	
	        }
		}
		else if(n/2<b){
	    	for(int j=1;j<=b-n/2;j++){
	    		int sszx=999999,zxcy;
	            for(int k=1;k<=n;k++){
	            	if(cy[k].d==2&&cy[k].ss<=sszx){
	            	zxcy=k;
	            	sszx=cy[k].ss;
	            	cout<<k;
				}
				}

				sum-=cy[zxcy].ss;
				cy[zxcy].ss=9999999;
	        }
		}
		else if(n/2<c){
	    	for(int j=1;j<=c-n/2;j++){
	    		int sszx=999999,zxcy;
	            for(int k=1;k<=n;k++){
	            	if(cy[k].d==3&&cy[k].ss<=sszx){
	            	zxcy=k;
	            	sszx=cy[k].ss;
				}
				}
				sum-=cy[zxcy].ss;
				cy[zxcy].ss=9999999;
	        }
		}
		cout<<sum<<endl;
	}
}
