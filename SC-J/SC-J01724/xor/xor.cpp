#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],s[500005],maxn;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=n;i>0;i--){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==m)ans[i]=max(ans[i],ans[j+1]+1);
		}
		maxn=max(ans[i],maxn);
		ans[i]=maxn;
	}
	cout<<maxn;
	return 0;
}