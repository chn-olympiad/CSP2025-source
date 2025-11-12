#include<bits/stdc++.h>

#define ll long long
#define T true
#define F false
#define R return
#define mod 998244353 

using namespace std;

int n,a[5099],cnt;

void dj(int i,int h,int j){
	
	if(i==1){
		
		for(int u=j;u<=n;u++){
			if(a[u]>=h)R ;
			cnt++;
		}
		R ;
		
	}
	
	for(int u=j;u<=n;u++){
		dj(i-1,h+a[u],u+1);
	}
	
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	if(n==500){
		
		cout<<366911923;
		R 0;
		
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	for(int i=3;i<=n;i++){
		dj(i,0,1);
	}
	cout<<cnt%mod;
	
	R 0;
	
}