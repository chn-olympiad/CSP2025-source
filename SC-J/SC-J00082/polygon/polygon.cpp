#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int d[5010];
int k[5010];
long long ans=0;

void dfs(int bian,int c){
	if(c>bian){
		long long cnt=0;
		for(int i=1;i<=bian;i++){
			cnt+=a[d[i]];
			k[i]=a[d[i]];
		}
		sort(k+1,k+bian+1);
		if(2*k[bian]<cnt){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=d[c-1]+1;i<=n;i++){
		d[c]=i;
		dfs(bian,c+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,1);
	}
	cout<<ans;
	return 0;
} 