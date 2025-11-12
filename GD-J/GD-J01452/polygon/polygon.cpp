#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005];
long long C(int n,int x){
	long long up=1;
	for(int i=n;i>=n-x+1;i--)up=((up%MOD)*i)%MOD;
	long long down=1;
	for(int i=1;i<=n-x+1;i++)down=((down%MOD)*i)%MOD;
	return up/down;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=0;
	if(cnt==n){
		for(int i=3;i<=n;i++)ans=(ans%MOD+C(n,i)%MOD)%MOD;
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
