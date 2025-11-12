#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,mod=998244353;
int n,a[maxn],maxx,ans;

void sol1(){
	ans=1;
	int cha=1+n+((n-1)*n)/2;
	for(int i=1;i<=n;++i){
		ans=ans*2%mod;
	}
	if(ans<cha){
		ans=ans+mod-cha;
	}else{
		ans-=cha;
	}
	cout<<ans;
}

int num[5000005];

void sol2(){
	maxx=a[1]+a[2];
	num[a[1]]++,num[a[2]]++,num[a[1]+a[2]]++;
	for(int i=3;i<=n;++i){
		if(maxx>a[i]){
			for(int j=a[i]+1;j<=maxx;++j){
				if(num[j]){
					ans=(ans+num[j])%mod;
				}
			}
		}
		for(int j=maxx;j>=a[1];--j){
			if(num[j]){
				num[j+a[i]]+=num[j];
			}
		}
		num[a[i]]++;
		maxx+=a[i];
	}
	cout<<ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maxx=a[n];
	if(maxx==1){
		sol1();
	}else{
		sol2();
	}
	return 0;
}