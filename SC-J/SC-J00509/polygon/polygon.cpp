#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005; 
int cmp(int m,int s){
	int cnto=1;
	for(int i=1;i<=s;i++){
		cnto*=i;
		if(i<=m) cnto/=i;
		if(i<=s-m) cnto/=i;
	}
	return cnto%mod;
}
int main(){
	
	int n,ans=0,t=0,num=0;
	int cnt=0;
	cin>>n;
	int a[N];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=3){
		if(n==3){
			for(int i=1;i<=n;i++){
				num+=a[i];
				t=max(t,a[i]);
			}
			if(num>2*t){
				ans=1;
			}
		}
		else ans=0;
	}
	
	else{
		for(int i=3;i<n;i++){
			ans+=cmp(i,n);
		}
		ans+=1;
		ans%=mod;
	}
	cout<<ans;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	return 0;
}