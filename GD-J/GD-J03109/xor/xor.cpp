#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+3,inf=0x3f3f3f3f;
int n,k,a[MAXN],pre[MAXN],clk,r[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		pre[i]=(pre[i-1]^a[i]);
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq;
	for(int i=1;i<=n;i++){
		r[i]=inf;
		if(a[i]==k){
			r[i]=i;
			pq.push({i,i});
			continue;
		}
		for(int j=i+1;j<=n;j++){
			if((pre[j]^pre[i-1])==k){
				r[i]=j;
				pq.push({j,i});
				break;
			}
		}
	}
	int ans=0,now=0;
	while(!pq.empty()){
		int r=pq.top().first,l=pq.top().second;pq.pop();
		if(l<=now)continue;
		ans++;
		now=r;
	}
	cout<<ans;
	return 0;
}
