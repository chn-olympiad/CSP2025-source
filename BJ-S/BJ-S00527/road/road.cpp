#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
long long n,m,k,u[N],v[N],w[N],c[11],a[10003],ans=0;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){cin>>u[i]>>v[i]>>w[i];q.push(w[i]);}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=1,y=2;
		for(int i=1;i<=n*(n-1)/2;i++){
			q.push(a[x]+a[y]+c[j]);
			if(y+1>n) x++,y=x+1;
			else y++;
		}
	}
	for(int i=1;i<n;i++){
		ans+=q.top();
		q.pop();
	}
	cout<<ans;
	return 0;
}
