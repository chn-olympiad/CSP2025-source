#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=0;
	}
	sort(a+1,a+n+1);
	if(flag){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		if(ans>2)cout<<(ans%mod-2+mod)%mod;
		else cout<<0;
		return 0;
	}
	if(a[1]+a[2]>a[3]){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
