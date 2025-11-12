#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,b;
	cin>>n>>m;
	int c[150]={};
	int len=n*m;
	for(int i=0;i<len;i++){
		cin>>c[i];
		if(i==0) a=c[i];
	}
	sort(c,c+len,cmp);
	for(int i=0;i<len;i++){
		if(c[i]==a){
			b=i+1;
			break;
		}
	}
	int x=1,y=1,z=1,l=0;
	while(1){
		if(z==b){
			cout<<y<<" "<<x;
			break;
		}
       	if(l==0){
       		x++;
       		z++;
       		if(x>n){
   				y++;
   				l=1;
    			x=n;
			} 
		}       
      	else if(l==1){
       		x--;
       		z++;
       		if(x<1){
   				y++;
   				l=0;
    			x=1;
			} 
		}
	}
    return 0;
}
