//GZ-S00227      李昀达       贵阳市双龙华麟学校 
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n,b1=0,b2=0,b3=0,c1=0,c2=0,c3=0,d1=0,d2=0,d3=0;
	cin>>n;
	int mm;
	mm=n/2;
	for(int a=1;a<=n;a++){
		cin>>b1>>b2>>b3;
		if(b1>b2){
			if(b1>b3){
				b1+=d1;
				c1++;
			}
		}
		if(b2>b1){
			if(b2>b3){
				b2+=d2;
				c2++;
				
			}
		}
		if(b3>b1){
			if(b3>b2){
				b3+=d3;
				c3++;
			}
		}
		if(b1>=mm){
			c1--;
			c2++;
		}
		if(b2>=mm){
			c2--;
			c3++;
		}
		if(b3>=mm){
			c3--;
			c1++;
		}
		int d1=b1;
		int d2=b2;
		int d3=b3; 
	}
	cout<<b1<<endl;
	cout<<b2<<endl;
	cout<<b3<<endl;
	
	feropen("club.in","r","in");
	feropen("club.out","w","out");
	//Ren5Jie4Di4Ling5%
	return 0;
}
