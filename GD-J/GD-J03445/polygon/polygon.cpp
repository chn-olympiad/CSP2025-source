#include <bits/stdc++.h>
const int mod=998244353;
using namespace std;
long long n,a[10010],b[1000010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=7;i<(1<<n);i++){
		long long t=i,s=0,cnt=0,sum=0,maxs=INT_MIN;
		memset(b,0,sizeof(b));
		while(t!=0){
			b[++s]=t%2;
			t/=2;
		} 
		for(int j=1;j<=s;j++){
			if(b[j]==1) sum+=a[j],maxs=max(maxs,a[j]),cnt++;
		} 
		if(sum>maxs*2 && cnt>=3){
			ans++;
			ans%=mod;
		} 
	}
	cout<<ans%mod;
	return 0;
}
