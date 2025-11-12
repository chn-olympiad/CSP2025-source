#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int a[N],ans=0,n,sum=0;
int slove(){
	int ans=1,ans2=1;
	for(int m=3;m<=n;m++){
		int ans1=1;
		for(int i=1;i<=n;m++){
			ans1=(ans*i)%mod;
		}
		ans=(ans+ans1/(n-m))%mod;
	}		
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==3){
		int t=max(a[1],max(a[2],a[3]));
		if(t<=sum) cout<<0;
		else cout<<3;
	}
	else{
		ans=slove();
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}