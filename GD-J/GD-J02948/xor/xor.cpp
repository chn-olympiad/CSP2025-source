#include<iostream>
#include<algorithm>
using namespace std;
int n,sum[500010],a[500010],f[500010],ans,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for (int i=1;i<=n;i++){
		if (a[i]==m)f[i]=1;
		for (int j=0;j<i;j++){
			if (((sum[i]^sum[j]))==m){
				f[i]=max(f[j]+1,f[i]);
			}
			f[i]=max(f[j],f[i]);
		}
	}
	for (int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout <<ans;
	return 0;
}
