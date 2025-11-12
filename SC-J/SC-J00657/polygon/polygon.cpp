#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn=0;
int b[5005];
int find(int x,int tot,int y){
	if(x==0&&(maxn*2)<tot) return 1;
	else if(x==0) return 0;
	int ans=0;
	for(int i=y;i<=n-x+1;i++){
		if(b[i]==0){
			b[i]=1;
			maxn=max(maxn,a[i]);
			int t=(find(x-1,tot+a[i],i+1))%998244353;
			maxn=0;
			ans+=t;
			ans%=998244353;
			b[i]=0;
		}
	}
	return ans%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++) std::cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=(find(i,0,1))%998244353;
		ans%=998244353;
		maxn=0;
	}
	std::cout<<ans%998244353;
	return 0;
} 