#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a[3][100005];
int does(){
	int n;
	cin>>n;
	int res=0,x=0,y=0,z=0;
	vector<int>o,p,q;
	for(int i=1;i<=n;i++) for(int j=0;j<3;j++) cin>>a[j][i];
	for(int i=1;i<=n;i++){
		if(a[0][i]>=a[1][i]&&a[0][i]>=a[2][i]) x++,o.push_back(a[0][i]-max(a[1][i],a[2][i]));
		else if(a[1][i]>=a[0][i]&&a[1][i]>=a[2][i]) y++,p.push_back(a[1][i]-max(a[0][i],a[2][i]));
		else z++,q.push_back(a[2][i]-max(a[1][i],a[0][i]));
		res+=max(a[0][i],max(a[1][i],a[2][i]));
	}
	sort(o.begin(),o.end()),sort(p.begin(),p.end()),sort(q.begin(),q.end());
	if(x>n/2) for(int i=0;i<x-n/2;i++) res-=o[i];
	if(y>n/2) for(int i=0;i<y-n/2;i++) res-=p[i];
	if(z>n/2) for(int i=0;i<z-n/2;i++) res-=q[i];
	return res;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cout<<does()<<"\n";
	}
	return 0;
}
