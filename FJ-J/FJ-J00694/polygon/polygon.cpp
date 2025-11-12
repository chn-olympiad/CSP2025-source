//polygon.cpp
#include<bits/stdc++.h>
using namespace std;
int n,a[5001],b[5001];
//void f(int x){
//	if(x==3){
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j+1<=n;j++){
//				
//			}
//		}
//	}
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
	}
	for(int i=3;i<=n;i++){
		for(int j=1;(j+i-1)<=n;j++){
			 for(int j1=1;j+j1)
		}
	}
	return 0;
}
