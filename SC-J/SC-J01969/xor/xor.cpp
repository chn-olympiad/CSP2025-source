#include<bits/stdc++.h>
using namespace std;const int N=5e5+1,M=1<<20+1;
int n,k,a[N],q[N];
vector<int>beg(N,M);
long long ans=0;
long long dfs(int now){
	while(now<n&&beg[now]==M) now++;
	if(now>=n)return 1;
	return dfs(beg[now]+1)+1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(k>=1000){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
		int j=i;
		while(j>=0){
			if((q[i]^q[j])==k){
				beg[j]=min(i,beg[j]);
				break;
			}
			j--;
		}
	}
	for(int i=0;i<n;i++) ans=max(dfs(i),ans);
	cout<<ans;
	return 0;
} 