#include<bits/stdc++.h>
using namespace std;
int a,b,c[10000],d,e,f,g,h,j;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	d=a*b;
	cin>>e;
	for(int i=1;i<=d-1;i++){
		cin>>c[i];
		if(c[i]>e){
			f++;
		}
	}
	if((f+1)%a==0){
		g=(f+1)/a;
	}else{
		g=(f+1)/a+1;
	}
	h=f+1-(g-1)*a;
	if(g==1){
		cout<<g<<" "<<f+1;
	}else if(g%2==1){
		cout<<g<<" "<<h;
	}else{
		j=a-h+1;
		cout<<g<<" "<<j;
	}
	return 0;
	
} 
