#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[101];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int b=a[0];
	sort(a,a+n*m,cmp);
	int w;
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			w=i;
			break;
		}
	}
	int c=0,l=0,h=0;
    for(int i=0;i<m;i++){
    	if(i%2==0){
    		h=0;
    		for(int j=0;j<n;j++){
    		    h+=1;
    		    if(c==w){
    			    cout<<l+1<<" "<<h;
    			    return 0;
		        } 
		        c+=1;
		    }
		}
        else{
        	h=n;
        	for(int j=0;j<n;j++){
    		    h-=1;
    		    if(c==w){
    			    cout<<l+1<<" "<<h+1;
    			    return 0;
		        } 
		        c+=1;
		   }
		}
		l+=1;
	}
	return 0;
}
