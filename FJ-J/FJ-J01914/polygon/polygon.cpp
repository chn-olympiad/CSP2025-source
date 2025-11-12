#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[50005];
bool vi[50005]={0};
long long ans,cnt,maxn,maxnn;
void dfs(int s,int re) {
	if(s>=3&&cnt>2*maxn&&s<=n){
		ans++;
	}
	for(int i=re; i<=n; i++) {
		if(vi[i]==0) {
			vi[i]=1;
			cnt+=a[i];
			maxnn=maxn;
			maxn=max(maxn,a[i]);
			dfs(s+1,i+1);
			maxn=maxnn;
			cnt-=a[i];
			vi[i]=0;
		}
	}
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	maxn=a[1];
	dfs(0,1);
	cout<<ans;
	return 0;
}

