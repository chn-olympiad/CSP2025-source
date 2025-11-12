#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m;
bool check(long long mid){
	long long cnt=0,sum=0;
	for(int i=1; i<=n; i++){
		sum=sum^a[i];
		if(sum==m){
			sum=0;
			cnt++;
		}
	}
	return (cnt>=mid);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&m);
	bool f=0,f1=0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]!=a[i-1]) f=1;
		if(a[i]>2) f1=1;
	}
	if(f==0){
		printf("%d",n/2);
		return 0;
	}
	long long l=0,r=n+2,ans,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
