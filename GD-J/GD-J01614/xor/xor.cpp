#include<bits/stdc++.h>
using namespace std;
int n,k;
int f=1;
int a[500010];
int solve1(){
	cout<<n/2;
	return 0;
}
int solve2(){
	int ans=0,m=1;
	if(k==1){
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&i+1<=n){
				ans++;
				if(i+2<=n)i+=2;
			}
		}
		int ans2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans2++;
		}
		ans=max(ans2,ans);
	}
	cout<<ans;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	int ans1=0;
	if(k==0&&f)solve1();
	else if(n<=200010&&k<=1)solve2();
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans1++;
			}
		}
		cout<<ans1;
	}
	return 0;
}
