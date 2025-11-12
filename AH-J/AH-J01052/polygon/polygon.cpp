#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,cnt;
int a[5005];
int jc(int x){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans=ans*i%mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		int ans=(jc(n)%mod)/(jc(i)%mod);
		cnt=(cnt+ans)%mod;
	}
	cout<<cnt;
	return 0;
} 
