#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[5005];
bool f[5005];
int n;
int ans=0;
void choose(int x,int y,int z){
	f[x]=true;
	if(y==z){
		int t=0;
		for(int i=0;i<n;i++){
			if(f[i]){
				t+=a[i];
			}
		}
		if(t>(2*a[x])){
			ans++;
			ans%=998244353;
//			for(int i=0;i<n;i++){
//				if(f[i]){
//					cout<<i+1<<' ';
//				}
//			}
//			cout<<'/'<<' '<<x<<' '<<t<<endl;
		}
		f[x]=false;
		return;
	}
	for(int i=x+1;i<n;i++){
		choose(i,y+1,z);
		
	}
	f[x]=false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		f[i]=false;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]>a[2]){
			cout<<1;
			return 0; 
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<n;j++){
			choose(j,1,i);
		}
	}
	cout<<ans;
	return 0; 
}