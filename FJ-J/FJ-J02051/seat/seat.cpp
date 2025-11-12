#include<bits/stdc++.h>
using namespace std;
int s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,f,c=1,d=1;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>s[i];
	}
    a=s[1];
    sort(s+1,s+b+1);
    f=1;
	for(int i=b;i>=1;i--){
	    if(s[i]==a){
	    	cout<<d<<" "<<c;
	    	break;
		}
	    else{
	    	if(f==1){
	    		c++;
				if(c==n){
					f=2;
				}
			}
		    else if(f==2){
		    	d++;
		        if(c==1){
		        	f=1;
				}
			    else{
			    	f=3;
				}
			}
		    else{
		    	c--;
		    	if(c==1){
		    		f=2;
				}
			}
		}
	}
    return 0;
}
