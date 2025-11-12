#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string z="",s;
	int d=0;
	char x;
	cin>>s;
	int w=sizeof(s);
	
	for(int i=0;i<w;i++){
		if(s[i]<='9' && s[i]>='0'){
		
			z[d]=s[i];
				d++;
		}
	}
	for(int i=0;i<d;i++){
		for(int y=1;y<=d;y++){
	         if(z[y-1]>z[y]) {
	         	x=z[y-1];
	         	z[y-1]=z[y];
	         	z[y]=x;
			 }  
	    }
	}
	for(int i=d;i>=0;i--){
		cout<<z[i];
	}
	return 0;
}
