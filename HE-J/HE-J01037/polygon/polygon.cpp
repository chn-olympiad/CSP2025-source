#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[5006],p,flag=0;
long long ans=0;
long long jc(int n,int m){
	long long ans=1;
	for(int i=n;i<=m;i++){
		ans*=i;
	}
	return ans;
}
long long zuhe(int n,int m){
	return jc(n-m,n)/jc(1,n-m);	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3&&a[n]<a[0]+a[1]){
		cout<<1;
	}else{
		cout<<0;
	}
 fclose(stdin);
 fclose(stdout);
	return 0;
}
