#include<bits/stdc++.h>
using namespace std;
deque<int>d;
int a[5005],sum[5005],k,n,ans,flag=1;
int qpow(int a,int b){
	if(b&1){
		int tp=qpow(a,b/2)%998244353;
		return (a*tp%998244353)*tp%998244353;
	}else{
		int tp=qpow(a,b/2)%998244353;
		return (tp%998244353)*tp%998244353;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag==1){
		printf("%d",((qpow(2,n)-n)%998244353-n*(n-1)/2)%998244353);
	}
	k=3;
	for(;k<=n;k++){
		for(int i=1;i<=k;i++){
			while(d.size()&&d.front()<a[i]){
				d.pop_front();
			}
			while(d.size()&&d.back()<a[i]){
				d.pop_back();
			}
			d.push_back(a[i]);
		}
		for(int i=k;i<=n;i++){
			if(i>k){
				d.pop_front();
			}
			while(d.size()&&d.front()<a[i]){
				d.pop_front();
			}
			while(d.size()&&d.back()<a[i]){
				d.pop_back();
			}
			d.push_back(a[i]);
			if(sum[i]-sum[i-k]>2*d.front()){
				ans=(ans+1)%998244353;
				// printf("%d %d %d %d %d\n",ans,d.front(),sum[i]-sum[i-k],i,k);
			}				
		}
	}
	printf("%d\n",ans);
	return 0;
}