#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n;
int a[500005],ans1[500005];
bool fa=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) fa=0;
	}
	if(n<=3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else if(fa){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans1[i]=(ans1[i-1]*2LL+i-2)%mo;
			ans=(ans+ans1[i])%mo;
		}
		cout<<ans%mo;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}