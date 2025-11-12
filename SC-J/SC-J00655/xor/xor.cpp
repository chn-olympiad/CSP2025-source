#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int sum[500010];
vector<int>vis(1100010,-1);
int main(){
	fre("xor");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,nxt=0,ans=0;
	cin>>n>>k;
	vis[0]=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum[i]=sum[i-1]^x;
		int a=k^sum[i];
		if(vis[a]!=-1&&vis[a]+1>nxt){
			nxt=i;
			ans++;
		}
		vis[sum[i]]=i;
	}
	cout<<ans;
}