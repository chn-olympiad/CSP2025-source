#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,k;
int sum[N];
bool vis[N];
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum[i]=sum[i-1]^x;
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(vis[l]||vis[r]) continue;
			int x=sum[r]^sum[l-1];
			if(x==k){
//				cout<<l<<" "<<r<<" ";
//				int a=sum[r]^sum[l-1];
//				cout<<a<<endl;
				ans++;
				for(int i=l;i<=r;i++){
					vis[i]=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
