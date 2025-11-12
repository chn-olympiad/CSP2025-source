#include"bits/stdc++.h"
using namespace std;
typedef unsigned int ut;
const ut M=1<<20,N=5e5+5;;
ut pre[M],a[N],n,k,ans,last;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(ut i=1;i<=n;++i)
	cin>>a[i],a[i]^=a[i-1];
	for(ut i=1;i<=n;++i){
		if((pre[a[i]^k]>=last&&pre[a[i]^k]>0)||((a[i]^k)==0&&last==0)){
			++ans;
			last=i;
		}
		pre[a[i]]=i;
	}
	cout<<ans;
}	

