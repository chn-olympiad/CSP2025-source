#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010];
int c,my;
int m(int x,int y){
	int cnt7=0,f=0;
	while(y){
		y%=10;
		cnt7++;
	}
	for(int i=1;i<=cnt7-1;i++){
		f+=y%10;
	}
	if(x>=y){
		int cnt2=y/10;
		return x+cnt2;		
	}
	else{
		int e=x/=10;
		m(e,f);
	}
}
int main(){
    cin>>a;
	 for(int i=1;i<=a.size();i++){
    	if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
    		c++;
		}
	}
	long d=1;
	for(int i=1; i<=c-1;i++){
		d*=10;
	}
	for(int i=1;i<=a.size();i++){
    	if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]==9){
			 for(int j=1;j<=d;j*10){
				 if(a[i]*(d/10)>my){
				 	int cnt1=my/10;
				 	my=a[i]*(d/10)+cnt1;
				 }
				 else{
				 	my+=m(a[i]*(d/100),my);
				 }
				      
				 }
			 }
		}
	
	cout<<my;
	
	return 0;
}

