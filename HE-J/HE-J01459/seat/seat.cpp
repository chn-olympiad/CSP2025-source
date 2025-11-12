#include <bits/stdc++.h>
using namespace std;
int c[256],d[16][16];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,e=0,y=0,f=0;
	cin>>a>>b;
	cin>>c[1];
	e=c[1];
	for(int i=2;i<=a*b;i++){
		cin>>c[i];
	}
	sort(c,c+a*b+1);
	for(int i=1;i<=b;i++){
		if(y==0){
			for(int j=1;j<=a;j++){
				d[j][i]=c[f];
				f++;
			}
			y=1;
		}else{
			
			for(int j=a;j>=1;j--){
				d[j][i]=c[f];
				f++;
			}
			y=0;
		} 
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(d[j][i]==e){
				cout<<j<<' '<<i;
				
			}
		}
	}
	
	return 0;
}
