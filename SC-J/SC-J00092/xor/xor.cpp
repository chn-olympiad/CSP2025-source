#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
long long n,m,k,a[500005],sum[500005],ans,p[500005];
bool flag=false;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int l=1;l<=n;){
		for(int r=l;r<=n;r++){
			if((sum[r]^sum[l-1])==k){
				p[l]=r,l=r+1;
				break;
			}
			else if(r==n){
				flag=true;
				break;
			}
		}
		if(flag){
			p[l]=n+1;
			break;
		}
	}
//	for(int i=1;i<=n;i++) cout<<p[i]<<" ";
	for(int i=1;i<=n;) i=p[i]+1,++ans;
	cout<<ans;
	return 0;
}

/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/