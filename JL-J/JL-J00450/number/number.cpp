#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	int n;
	int a,b,c,d,e,f,x,y,z,l;
	string s[n];
	for(int i=0;i<n;i++){
		if(s[i]==1){
			a++;
		}
		if(s[i]==2){
			b++;
		}
		if(s[i]==3){
			c++;
		}
		if(s[i]==4){
			d++;
		}
		if(s[i]==5){
			e++;
		}
		if(s[i]==6){
			f++;
		}
		if(s[i]==7){
			x++;
		}
		if(s[i]==8){
			y++;
		}
		if(s[i]==9){
			z++;
		}
		if(s[i]==0){
			l++;
		}else{
			i++;
		}
	}
	int j=a+b+c+d+e+f+x+y+z+l;
	while(j==0){
		if(z>0){
			cout<<9;
			j--;
		}
		if(y>0){
			cout<<8;
			j--;
		}
		if(x>0){
			cout<<7;
			j--;
		}
		if(f>0){
			cout<<6;
			j--;
		}
		if(e>0){
			cout<<5;
			j--;
		}
		if(d>0){
			cout<<4;
			j--;
		}
		if(c>0){
			cout<<3;
			j--;
		}
		if(b>0){
			cout<<2;
			j--;
		}
		if(a>0){
			cout<<1;
			j--;
		}
		if(l>0){
			cout<<0;
			j--;
		}
	}
	return 0;
}
