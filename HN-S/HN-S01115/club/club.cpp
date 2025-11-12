#include<bits/stdc++.h>
using namespace std;
int t,n; 
struct C{
	long long r,d;
};
C u,v,w ;

long long a[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		u.d=0; 
		v.d=0; 
		w.d=0; 
	    for(int i=1;i<=n;i++){
	         cin>>a[1];
			 cin>>a[2];
			 cin>>a[3];
			 int x=max(a[1],max(a[2],a[3])) ;
		if(x==a[1]){
			if(u.r*2<=n){
				u.d+=a[1];
				
			}else if(a[2]>a[3]&&v.r*2<=n){
				v.d+=a[2];
			}else w.d+=a[3];
		} else if(x==a[2]){
			if(v.r*2<=n){
				v.d+=a[2];
			}else if(a[1]>a[3]&&u.r*2<=n){
				u.d+=a[1];
			}else w.d+=a[3];
		}else if(x==a[3]){
			if(w.r*2<=n){
				w.d+=a[3];
			}else if(a[1]>a[2]&&u.r*2<=n){
				u.d+=a[1];
			}else v.d+=a[2];
		}        
        }
		
	   cout<<u.d+v.d+w.d<<endl;
    }
	return 0;
} 
