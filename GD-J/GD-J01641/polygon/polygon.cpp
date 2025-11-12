#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll pre[5010],a[5010],vis[5010];
int n;
int dfs(int idx,int sum,int s){
	if(idx==0){
		return sum>s;
	}
	return dfs(idx-1,sum+=a[idx],s)+dfs(idx-1,sum,s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		if(pre[i-1]<=a[i]){
			continue;
		}
		int l=1,r=i-1;
		while(l<r-1){
			int mid=(l+r)/2;
			if(pre[mid]>a[i]) r=mid;
			else l=mid; 
		}
		l++;
		ans+=dfs(l-1,a[l],a[i]);
	}
	cout<<ans;
	return 0;
}
