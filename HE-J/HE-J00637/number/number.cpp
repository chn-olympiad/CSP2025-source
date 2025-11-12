#include <bits/stdc++.h>
using namespace std;
bool t(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
long long a,c=1,y=3,w=3,q=1,z=0;
int b[100004];
cin>>a;
while(y!=0){
	y=a/10;
	w=a%10;
	b[c]=w;
	
	c++;
	a=a/10;
}
sort(b+1,b+c+1,t);
for(int i=c;i>=1;i--){
	z+=q*b[i];
	q*=10;
}
cout<<z/10;
	return 0;
	
}
