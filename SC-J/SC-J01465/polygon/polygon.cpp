#include <iostream>
using namespace std;
long long l,r,n,a[5001],maxn,b,ans=0,mod=998244353;
void xs(int m,int ji,int ce){
	if(m==ce-1){
		if(b>2*maxn){
			ans++;
			ans%=mod;
			return;
		}
	}
	int maxj;
	if(n-ji-1<m-ce){
		return;
	}
	for(int i=ji+1;i<n;i++){
		b+=a[i];
		maxj=maxn;
		maxn=max(maxn,a[i]);
		xs(m,i,ce+1);
		maxn=maxj;
		b-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		xs(i,-1,1);
	}
	cout<<ans;
	return 0;
}