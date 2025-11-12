#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
const int INF=998244353;
int add(int x,int y){
	int ans=1;
	for(int i=y;i<=x;i++){
		ans*=i;
		ans%=INF;
	}
	return ans;
}
int add2(int x,int y){
	int ans=0;
	for(int i=x;i<=y;i++)ans+=a[i];
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int flag=0;
		for(int i=1;i<=n;i++)
			flag+=a[i];
		if(flag>maxa*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxa==1){
		int ans=1;
		for(int i=n-3;i>0;i--)
			ans+=add(n,n-i+1)%INF;
		cout<<ans%INF;
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>=3;i--){
		int mmax=a[i];
		int j=1,k=i-1;
		while(add2(j,k)>mmax&&j<=k){
			ans++;ans%=INF;
			j++;
		}
		j=1,k=i-1;
		while(add2(j,k)>mmax&&j<=k){
			ans++;ans%=INF;
			k--;
		}
	}
	cout<<ans;
	return 0;
}
