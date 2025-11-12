#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N],an[N],cnt,maxt[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	an[0]=k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		an[i]=sum[i]^k;
	}
	int i=1;
	for(;i<=n;i++){
		int pos=n+1;
		for(int j=n;j>=i;j--){
			if(sum[j]^sum[i-1]==k) pos=j ;
		}
		maxt[i]=max(maxt[i],maxt[i-1]);
		if(sum[pos]^an[i-1]!=0) continue;
		
		else{
			ans=max(ans,maxt[i-1]+1);
			maxt[pos]=max(maxt[pos],ans);
		}
	}
	cout<<ans;
	return 0;
}
