#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",in);
freopen("seat.out","w",out);
int a,b;
int k,n,pm[105],p=0;
cin>>a>>b;
for(int i=1;i<=a*b;i++){
cin>>n;
if(i==1){
k=n;
}
pm[i]=n;
}
for(int i=1;i<=a*b;i++){
	if(k<pm[i])p++;
	}
	p+=1;
int h=ceil(p/b);
cout<<h;
if(h%2==1)cout<<p%b;
else cout<<b-(p%b)+1;
return 0;
}
