#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,ans=0;
	long long a[10005],s[10005];
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i],s[i]=s[i-1]^a[i];
	if(k==0){
		for(int i=1;i<=n;++i)
			if(a[i]==0) ans++;
		cout<<ans;return 0;
	}
	if(k==1){
		for(int i=1;i<=n;++i)
			if(a[i]==1) ans++;
		cout<<ans;return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			long long qsum=s[j]^s[i-1];
			if(qsum==k) {ans++,i=j;continue;}
		}
	}
	cout<<ans;
	return 0;
}
