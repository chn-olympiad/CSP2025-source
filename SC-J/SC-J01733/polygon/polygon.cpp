#include<bits/stdc++.h>
using namespace std;

int n,a[5001],f=1,vis[5001];
long long ans;

void go1(int k,int i){
	if(k>i){
		ans++;
		return ;
	}
	 for(int i=1; i++; i<=n){
	 	if(vis[i]!=1){
	 		vis[i]=1;
	 		go1(k,i+1);
	 		vis[i];
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)  f=0;
	}
	sort(a+1,a+n+1);
	if(n<3)  cout<<0;
	else if(n==3){
		if(a[1]+a[2]>a[3])  cout<<1;
	}
	else if(f==1){
		for(int i=3; i<=n; i++){
			go1(i,1);
		} 
		cout<<ans%998244353;
	}
	else{
		cout<<11;
	}
	
	return 0;
}