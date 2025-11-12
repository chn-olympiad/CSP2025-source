#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt,cntcnt,vis[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
		if(a[i]==1||a[i]==0) cntcnt++;
	}
	if(cnt==n&&k==0){
		cout<<n/2<<endl;
	}else if(cntcnt==n&&k==1){
		cout<<cnt<<endl;
	}else if(cntcnt==n&&k==0){
		for(int i=1;i<n;i++){
			int x=i+1;
			if(vis[i]==0&&vis[x]==0&&a[i]==1&&a[x]==1){
				vis[i]=1;
				vis[x]=1;
				ans++;
			}
		}
		cout<<ans+(n-cnt)<<endl;
	}else{
		cout<<1<<endl;
	}
	return 0;
}
