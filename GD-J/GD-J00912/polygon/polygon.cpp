#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<(1<<n);i++){
		int sum=0,maxn=0,cnt=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1)sum+=a[j+1],maxn=max(maxn,a[j+1]),cnt++;
		if(cnt>=3&&sum>2*maxn)ans=(ans+1)%mod;
	}
	cout<<ans;
	return 0;
}
