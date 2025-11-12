#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,t=0,y=0,r=0,e=0,w=0,q=0;
    cin>>n>>m;
    t=n*m;
    int a[t];
    for(int i=0;i<t;i++){
    	cin>>a[i];
    }
    y=a[0];
    for(int j=0;j<t;j++){
	    for(int i=0;i<t;i++){
	    	int u=0;
		if(a[i]>a[i-1]){
			u=a[i];
			a[i]=a[i-1];
			a[i-1]=u;
	        }
	    }
	}
	for(int i=0;i<t;i++){
		if(y==a[i]){
			r=i+2;
		}
	}
		if(r%4==1){
			cout<<r/n<<" "<<r%m;
		}else if(r%4==2){
			cout<<r/n<<" "<<r%m+1;
		}else if(r%4==3){
			cout<<r%n+1<<" "<<r%m+1;
		}else if(r%4==0){
			cout<<r%n+1<<" "<<r%m+1;
		}
	return 0;
}
