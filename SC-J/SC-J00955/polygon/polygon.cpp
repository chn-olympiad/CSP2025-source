#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0,maxn=0; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt+=a[i],maxn=max(maxn,a[i]);
	}
	if(n<3||cnt<=maxn*2) cout<<0<<"\n";
	else cout<<1<<"\n";
	return 0;
}