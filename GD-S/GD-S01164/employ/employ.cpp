#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ3.out","w",stdout);
	int n,m,p[505];
	char test[505];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>test[i];
	}
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	int man=n,ans=1;
	int outt=0;
	if(n==m){
		long long a=1; 
		for(int i=0;i<n;i++){
			if(p[i]==0 || test[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			a*=i;
		}
		ans=a%998244353;
		cout<<ans%998244353;
		return 0;
	}
	int t=0;
	outt=0;
	long long q=0;
	while(t==0){
		for(int i=0;i<n;i++){
			if(p[i]<=outt){
				outt++;
				man--;
			}
		}
		if(outt==q)t++;
		else q=outt;
	}
	long long a=1;
	ans-=1;
	for(int i=n-outt;i>=m;i--){
		a=1;
		for(int j=i;j>i-m;j--){
			a*=j;
		}
		for(int j=1;j<=m;j++){
			a/=j;
		}
		ans+=a%998244353;
	}
	cout<<ans%998244353;
	return 0;
}
