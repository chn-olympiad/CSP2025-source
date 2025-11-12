#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	long long sum=0;
	int mx=0;
	for(int i=1;i<=m;i++){
		int uu,vv,x;
		cin>>uu>>vv>>x;
		sum+=x;
		mx=max(mx,x);
	}
	cout<<sum-mx;
	return 0;
}
