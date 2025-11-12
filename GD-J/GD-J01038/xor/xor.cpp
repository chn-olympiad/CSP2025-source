#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int n,vis[N],ans;
long long k,a[N],sum[N];
void color(int f,int t){
	for(int i=f;i<=t;i++)vis[i]=1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[j])break;
			if((sum[j]^sum[i-1])==k){
				//cout<<i<<" "<<j<<" "<<(sum[j]^sum[i-1])<<endl;
				color(i,j);
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
