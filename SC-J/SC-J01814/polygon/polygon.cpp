#include<bits/stdc++.h>
using namespace std;
int n,w[5002];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) {
		cout<<0;
		return 0;
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int m=max(a,max(c,b)),all=a+b+c;
		if(all>m*2) cout<<1;
		else cout<<0;
		return 0;
	}
	bool bj=0;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		if(w[i]!=1) bj=1;
	}
	if(!bj) {
		unsigned long long ans;
		for(int i=1;i<=n-2;i++){
			ans+=i*(n-i-1);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	unsigned long long r;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int mm=max(i,max(k,j)),al=i+k+j;
				if(al>mm*2) r++;
				r%=998244353;
			}
		}
	}
	cout<<r;
	return 0;
}
