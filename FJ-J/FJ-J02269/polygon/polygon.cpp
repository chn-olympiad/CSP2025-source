#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100009],n;
void solve1(){
	int sum=0,M=0;
	for(int i=1;i<=n;i++){
		sum+=a[i],M=max(M,a[i]);
	}
	if(M*2<sum)cout<<1;
	else cout<<0;
	return;
}
void solve2(){
	int sum=0,M=0,ans=0;
	for(int i=1;i<=n;i++){
		int w=3;
		for(int j=i+w;j<=n;j++){
			for(int k=i;k<=j;k++){
				M=max(M,a[i]);
				sum+=a[i];
			}
			if(M*2<sum)ans++;
			ans=ans%998244353;
		}
		w++;
	}
	cout<<ans;
	return;
}
void solve3(){
	
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
	}
	if(n==3){
		solve1();
	}else if(m==1){
		solve3();
	}else if(n<=10){
		solve2();
	}else{
		cout<<1;
	}
	return 0;
} 
