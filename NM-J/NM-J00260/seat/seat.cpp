//666bro会不了一点 
#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int e=a*b;
	int c[e];
	for(int i=0;i<e;i++){
		cin>>c[i];
	}
	int a1=c[0];
	int d[e];
	for(int i=0;i<e;i++){
		int w = 0;
		for(int z=0;z < e;z++){
			if(c[z]!=-1){
				if(c[w]<c[z]){
					w = z;
				}
			}
		}
		d[i]=c[w];
		c[w]=-1;
	}
	int x,y;
	for(int i=0;i<e;i++){
		if(d[i]==a1){
			int me=i+1;
			if(me%a==0){
				x=me/a;
				y=a;
			}
			else{
				x=((me-(me%a))/a)+1;
				y=me%a;
			}
		}
	}
	if(x%2==0){
		cout<<x<<' '<<a+1-y<<endl;
	}
	else{
		cout<<x<<' '<<y<<endl;
	}		
}
