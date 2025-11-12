#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int b,l=0,m=-1,x;
string a;
cin>>a;
int f[a.size()+1];
for(int i=0;i<=a.size();i++){
	b=a[i];
	if(b>=48&&b<=57){
		f[l]=b-48;
		l++;
		}
}
for(int j=0;j<=l-1;j++){
m=-1;
for(int i=0;i<=l-1;i++){
	if(f[i]>m){
		m=f[i];
		x=i;
	}
}
cout<<m;
f[x]=-1;
}
return 0;
}
