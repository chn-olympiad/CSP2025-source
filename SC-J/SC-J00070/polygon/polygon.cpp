#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
int b[20000];
     int a,p,c,d;
	 cin>>a;

     for(int i=1;i<=a;i++)
     {   if(a<3){
     	cout<<0;
     	break;}
     	
     	else if(a>=3){
     			 cin>>p>>c>>d;
		if(p+c>d&&p+d>c&&c+d>p) {
     		cout<<1;
     		break;
		 }else cout<<0;
		 break;
	 }}
   
	 
	
	return 0;
}