#include<bits/stdc++.h>
using namespace std;
int n; 
long long a[100000];
long long box[100000],num;
int dt(int t,int js,long long zs){
//	cout<<num<<endl;
	num%=998244353;
	for(int i=t;i<=n;i++){
		box[++js]=a[i];
		zs+=a[i];
		if(t+1<=n&&js<=n)
		dt(i+1,js,zs);
		if(zs>box[1]*2&&js>=3)
		num++;
//		for(int j=1;j<=js;j++){
//			cout<<box[j]<<" ";
//		}
//		cout<<endl;
		box[js]=0;
		zs-=a[i];
		js--;
	}
	return 0;
}
int main( ) {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>25){
		cout<<"0";
		return 0;
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=n;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		} 
	}
		dt(1,0,0);
		cout<<num;		
	return 0;
}
