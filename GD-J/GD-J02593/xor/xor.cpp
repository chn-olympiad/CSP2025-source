#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int n,k,a[N],sum[21][N],b[N],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=20;j++){
			sum[j][i]=sum[j][i-1];
			if(a[i]>>(j-1)&1) sum[j][i]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int l=1;l<=20;l++){
				int o=k>>(l-1);
				if((o&&((sum[l][j]-sum[l][i-1])%2==0))||(!o&&((sum[l][j]-sum[l][i-1])%2))){
					flag=1;
					break;
				}
			}
			if(!flag){
				b[i]=j;
				break;
			}
		}
	}
	int K=1;
	while(K<=n){
		int num=0x3f3f3f3f;
		for(int i=K;i<=n;i++)
			if(b[i]) num=min(num,b[i]);
		if(num==0x3f3f3f3f) break;
		K=num+1;
		ans++;
	}
	cout<<ans;
	return 0;
}
