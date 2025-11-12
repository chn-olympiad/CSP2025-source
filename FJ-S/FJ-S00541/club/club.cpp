#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t,n,a,b,c,x=0,y=0,z=0,q;
cin>>t;
for(int i=1;i<=t;i++){
if(n==2)cin>>a>>b>>c;
if(a<b<c){
	z+=c;
}
if(a<c<b){
	y+=b;
}
if(b<a<c){
	z+=c;
}
if(b<c<a){
	x+=a;
}
if(c<a<b){
	y+=b;
}
if(c<b<a){
	x+=a;
}
q=x+y+z;
cout<<q<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}
