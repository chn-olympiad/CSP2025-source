#include <iostream>
#include <cstdio>
using namespace std;
int n,k,a[500005],sum[500005],t,ans;
void AC(int i,int t,int cnt){
	if(i==n+1){
		ans=max(ans,cnt);
		return;
	}
	if((sum[i]^sum[t])==k) cnt++,t=i;
	if(cnt+n-1<ans) return;
	AC(i+1,i,cnt);
	if(t!=i && i!=n) AC(i+1,t,cnt);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int rp = 1;rp <= n;rp++){
		scanf("%d",&a[rp]);
		sum[rp]=(sum[rp-1]^a[rp]);
//		cout<<sum[i]<<' ';
	}
	if(k==0){
		for(int rp = 1;rp <= n;rp++){
			if(a[rp]==0) ans++;
			else if(a[rp]==1 && a[rp-1]==1){
				ans++;
				a[rp]=0;
			}
		}
	}
	else if(k==1) for(int rp = 1;rp <= n;rp++) if(a[rp]==1) ans++;
	else if(k>1) AC(1,0,0);
	cout<<ans;
	return 0;
}
