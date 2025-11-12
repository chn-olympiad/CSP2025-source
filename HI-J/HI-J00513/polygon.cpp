#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
int a,c=0,d=0,e=1,f=1;
cin>>a;
int b[a]={};
for (int i=0;i<a;i++){
	cin>>b[i];

}

for (int j=0;j<=a-2;j++){
	
	while (e+j<=a-1){
		

		while (j+f<=a){
			d+=b[j]+b[j+e]+b[j+f];
			f++;
			if (d>(b[j+f])*2){
				c++;
			}
			
			
			}
		e++;
		f=e+1;
		
	}
	
}
	
		cout<<c;
return 0;
}
