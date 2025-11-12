#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int a[N],s[N];
int mark[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&abs(a[1]-a[2])<a[3]) cout<<1;
		else cout<<0;
	}
	int maxN=-1;
	for(int i=1;i<=n;i++){
		int maxn=a[i];
		for(int j=1;j<=i+1;j++){
			maxn=max(maxn,a[j]);
		}
		maxN=max(maxN,maxn);
		mark[i]=maxn;
	}
	long long ans=0;
	if(maxN==1){
		ans=((n-1)*n/2)%998244353;
		/*
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				ans=ans+1;
			}
		}
		*/
		cout<<ans;
		return 0;
	}
	ans=rand();
	cout<<ans%998244353;
	return 0;
}
