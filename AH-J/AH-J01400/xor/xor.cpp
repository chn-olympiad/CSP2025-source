#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,b[500005],t[500005],maxr;
void dfs(int cnt,int r){
	for(int i=r+1;i<=n;i++){
		if(b[i]>=i){
			if(b[i]>=maxr){
				ans=max(ans,cnt+1);
				return;
			}
			dfs(cnt+1,b[i]);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int l=1;l<=n;l++){
		memset(t,0,sizeof(t));
		for(int r=l;r<=n;r++){
			if(r==l)t[r]=a[l];
			else t[r]=t[r-1]^a[r];
			if(t[r]==k){
				b[l]=r;
				maxr=max(maxr,r);
				break;
			}
		}
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
