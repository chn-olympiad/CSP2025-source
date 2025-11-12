#include<bits/stdc++.h>
using namespace std;
long long a[10000];
bool ban[10000];
long long n;
long long b;
int di(int h,bool lo){
	if(h>b)return 0;
	long long s=0;
	long long zui=-100;
	if(h<3){
		di(h+1,0);
		di(h+1,1);
	}else{
	ban[h]=lo;
	if(lo!=0){
	for(int i=1;i<=h;i++){
		if(ban[i]==1){
			s+=a[i];
			if(a[i]>zui)zui=a[i];
		}
	}	
	if(s>=zui*2){
	n=(n+1)%1998244353;
	
}
	
}
	di(h+1,0);
	di(h+1,1);
	ban[h]=0;
	}
	
}
int main (){
freopen("polygon.in","r",stdin); 
freopen("polygon.out","w",stdout);
cin>>b;
for(int i=1;i<=b;i++)cin>>a[i];
di(0,1);
di(0,0);
cout<<n+1;
return 0;
}
