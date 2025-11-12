#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ta[5005];
int f(int x,int k,int i){
	int s=0;
	for(;i<x;i++){
		if(k-a[i]<=0) break;
		if(k-a[i]>0) s=(s+1+f(x,k-a[i],i+1))%998244353;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ta[0]=0;
	for(int i=1;i<=n;i++)
		ta[i]=ta[i-1]+a[i];
	
	for(int i=3;i<=n;i++){
		if(ta[i-1]-a[i]>0)
			s=(s+1+f(i,ta[i-1]-a[i],1))%998244353;
	}
	cout<<s;
	freopen("polygon.out","w",stdout);
	return 0;
} 
