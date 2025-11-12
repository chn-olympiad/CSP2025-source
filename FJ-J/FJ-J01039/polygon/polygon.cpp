#include<bits/stdc++.h>
using namespace std;
#define maxx(a,b,c) a>b?a>c?a:c:b>c?b:c
//#define r(i,n) for(;i<=n;i++)
const int N=1e9+7;
long long s,u,l,manx=-N,j=1;
long long a[5005],b[5005];
void ds(int j,int k){
	if(j>k)return ;
//	u=0;
	for(;j<=k;j++){
		if(j>k)return;
		u+=a[j];
		if(j<=k)
		ds(j+1,k);
		if(manx<a[j])manx=a[j];
//		if(manx*2<u)s++;
	}
	
}
//	u++;
//void f(int k){
////	
//}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	
	if(n==3){
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]+a[2]+a[3]>maxx(a[1],a[2],a[3])*2){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=3;k<=n;k++){
//		ds
//	ds(i,k);
		u=0;
		manx=-N;
		ds(j,k);
			if(manx*2<u)s++;
	}
	cout<<s%998244353;
	return 0; 
}  
