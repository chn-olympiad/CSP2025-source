#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[1000005],c[15],sum;

int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>w[i];
	sort(w+1,w+1+m);
	for(int i=1;i<n;i++) sum+=w[i];
	cout<<sum;
	return 0;
}
