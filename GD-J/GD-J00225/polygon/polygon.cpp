#include<bits/stdc++.h>
#define int long long
#define mo 998244353
using namespace std;
int n,ans;
int a[5005],s[5005],f[5005];
int u(int p,int q){
	int k=1;
	while(q){
		if(q&1) k=k*p%mo;
		p=p*p%mo;
		q/=2;
	}
	return k;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=0;j<(1<<(i-1));j++){
			int sum=0; 
			for(int k=0;k<i-1;k++){
				if((1<<k)&j){
					sum+=a[k+1];
				} 
			}
			if(sum>a[i]) ans=(ans+1)%mo;
		}
	}
	cout<<ans;
}
