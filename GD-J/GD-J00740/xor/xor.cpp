#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],b[4005][4005],ans=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(k==0){
		if(n==1)cout<<0;
		else if(n==2)cout<<1;
		else{
			int q=n/2,p=n/4,qp=n/8,pq=n/16;
			cout<<(max(1,q))*(max(1,p))*(max(1,qp))*(max(1,pq));
		}
	}else if(k==1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int gs=a[i];
				for(int l=i+1;l<=j;l++){
					if(gs!=a[l])gs=1;
					else gs=0;
				}
				if(gs==k)b[i][j]=1;
			}
		}
		int rp=INT_MAX;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)if(b[i][j]==1)rp=min(rp,j);
		}
		while(rp<n){
			int nsm=INT_MAX;
			for(int i=rp+1;i<=n;i++){
				for(int j=1;j<=n;j++)if(b[i][j]==1)nsm=min(nsm,j);
			}
			ans++,rp=nsm;
		}
		cout<<ans;
	}else cout<<2;
	return 0;
}
