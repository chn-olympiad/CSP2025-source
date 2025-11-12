#include<bits/stdc++.h>
using namespace std;
long long f[500005],n,k,p[500005],a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)	cin>>a[i],f[i]=a[i];
	for(long long i=1;i<=n;i++) if(f[i]==k) p[i]++,ans++;
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=n-i+1;j++){
			f[j]=f[j]^a[i+j-1];
			if(p[i+j-1]) p[j]+=p[i+j-1];
			if(f[j]==k&&!p[j]){
				p[j]++;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
