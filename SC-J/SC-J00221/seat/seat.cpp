#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int bb[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int a,b,c,d,e,g=1,x=1,y=0,f=0;
cin>>a>>b;
for(int i=1;i<=a*b;i++){
   cin>>bb[i];
}
d=bb[1];
sort(bb+1,bb+a*b+1);
    for(int i=a*b;i>=1;i--){
    
    	if(y==1&&i!=a*b-1&&g==-1){
    		x++;
    		y--;
    		g=1;
		}
		else if(y==a&&g==1){
			x++;
			y++;
			g=-1;
		}
			y+=g;
	//	cout<<x<<' '<<y<<endl; 
		if(bb[i]==d){
			cout<<x<<' '<<y<<endl;
			break;
		}
	}
	return 0;
}