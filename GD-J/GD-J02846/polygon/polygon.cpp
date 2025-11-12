#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],vis[5005],ans,cnt;
long long p1[5005],p2[5005],p3[5005],p4[5005];
void dfs(int pos,int sum,int last){
	if(pos>=3){
		if(sum>a[last]*2){
			ans++;
			if(ans>=998244353)
			ans=ans%998244353;
		}
	}
	for(int i=last;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(pos+1,sum+a[i],i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cnt++;
		}
	}
	if(cnt==n){
		p1[1]=8;
		for(int i=2;i<=5004;i++){
			p1[i]=p1[i-1]*2;
			p1[i]=p1[i]%998244353;
			cout<<p1[i]<<endl;
		}
		p2[1]=7;
		for(int i=2;i<=5004;i++){
			p2[i]=p2[i-1]+p1[i-1];
			p2[i]=p2[i]%998244353;
		}
		p3[1]=4;
		for(int i=2;i<=5004;i++){
			p3[i]=p3[i-1]+p2[i-1];
			p3[i]=p3[i]%998244353;
		}
		p4[1]=1;
		for(int i=2;i<=5004;i++){
			p4[i]=p4[i-1]+p3[i-1];
			p4[i]=p4[i]%998244353;
		}
		cout<<p4[n-2];
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,1);
	if(ans>=998244353)ans=ans%998244353;
	cout<<ans; 
	return 0;
} 
