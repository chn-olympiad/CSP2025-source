#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,a[5005];
void f(long long m1,long long m,long long y,long long z,long long x){
	if(m>=3 && y>2*z && m1!=m){
		ans++;
	}
	if(x==n){
		return ;
	}
	if(a[x+1]>z){
		f(m,m+1,y+a[x+1],a[x+1],x+1);
	}else{
		f(m,m+1,y+a[x+1],z,x+1);
	}
	f(m,m,y,z,x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	f(0,0,0,0,0);
	cout<<ans%998244353;
	return 0;
}
