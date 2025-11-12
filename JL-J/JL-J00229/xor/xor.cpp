#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],pre[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k,res=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=(pre[i-1]^a[i]);
	}
	for(int l=1;l<=n;l++){
		int r=l;
		for(;r<=n;r++){
			if((pre[l-1]^pre[r])==k)break;
		}
		l=r;
		res++;
	}
	cout<<res;
	return 0;
}
