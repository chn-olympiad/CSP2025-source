#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int y0=0,y1=0,y2=0,y3=0,y4=0,y5=0,y6=0,y7=0,y8=0,y9=0;
	string a;
	cin>>a;
	
	for(int b=0;b<a.length();b++){
		if(a[b]=='1'){
			
			y1++;
		}
		if(a[b]=='2'){
			
			y2++;
		}
		if(a[b]=='3'){
			
			y3++;
		}
		if(a[b]=='4'){
		
			y4++;
		}
		if(a[b]=='5'){
			
			y5++;
		}
		if(a[b]=='6'){
			
			y6++;
		}
		if(a[b]=='7'){
			
			y7++;
		}
		if(a[b]=='8'){
			
			y8++;
		}
		if(a[b]=='9'){
		
			y9++;
		}
		if(a[b]=='0'){
			
			y0++;
		}
	}
	if(y1+y2+y3+y4+y5+y6+y7+y8+y9==0){
		cout<<0;
	}else{
		for(int yx9=0;yx9<y9;yx9++){
			cout<<9;
		}
			for(int yx8=0;yx8<y8;yx8++){
			cout<<8;
		}
			for(int yx7=0;yx7<y7;yx7++){
			cout<<7;
		}
			for(int yx6=0;yx6<y6;yx6++){
			cout<<6;
		}
			for(int yx5=0;yx5<y5;yx5++){
			cout<<5;
		}
			for(int yx4=0;yx4<y4;yx4++){
			cout<<4;
		}
			for(int yx3=0;yx3<y3;yx3++){
			cout<<3;
		}
			for(int yx2=0;yx2<y2;yx2++){
			cout<<2;
		}
			for(int yx1=0;yx1<y1;yx1++){
			cout<<1;
		}
			for(int yx0=0;yx0<y0;yx0++){
			cout<<0;
		}
	}
	return 0;
}

