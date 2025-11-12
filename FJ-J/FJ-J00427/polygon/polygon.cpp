#include<bits/stdc++.h>
using namespace std;
int n,a[5005],gox[50005];
int count(int x,int k){
	if(x==n)return n%998244353;
	else{
		if(gox[x]!=0)return gox[x]%998244353;
		else return gox[x]=count(x+1,(x*k+1))*(x*k+1)%998244353;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3&&a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
		cout<<1;
		return 0;
	}
	else if(n==3){
		cout<<0;
		return 0;
	}
	bool f=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			f=0;
			break;
		}
	}
	if(f==1){
		cout<<count(1,1)%998244353;
		return 0;
	}
	return 0;
}
