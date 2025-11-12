#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
bool all1(){
	for(int i=0;i<n;i++)if(a[i]!=1)return 0;
	return 1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(n==3){
		if(a[2]<a[0]+a[1])printf("1");
		else printf("0");
		return 0;
	}else if(all1()){
		int x=n+n*(n-1)/2+1;ans=1;
		for(int i=0;i<n;i++)ans=(ans*2)%998244353;
		ans-=x;
		if(ans<0)ans+=998244353;
		printf("%d",ans);
		return 0;
	}
	int s=1<<n;
	for(int i=0;i<s;i++){
		int cnt=0,mx=-1,sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				mx=max(mx,a[j]);
				sum+=a[j];
				cnt++;
			}
		}
		if(cnt<3)continue;
		if(sum>mx*2){
			ans++;
			ans%=998244353;
		}
	}printf("%d",ans);
	return 0;
} 
