#include<bits/stdc++.h>
using namespace std;
long long a[100001];
long long ans,n;
void go(long long i,long long sum,long long maxa,long long step){
	if(step>=3){
		if(sum>2*maxa){
			ans++;
			ans=ans%998244353;
		}
	}
	for(int j=i;j<=n;j++){
		sum+=a[j];
		long long t=maxa;
		maxa=max(maxa,a[j]);
		step++;
		go(j+1,sum,maxa,step);
		maxa=t;
		sum-=a[j];
		step--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	go(1,0,0,0);
	cout<<ans;
	return 0;
}