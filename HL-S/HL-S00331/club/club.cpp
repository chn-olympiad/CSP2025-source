#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int id,a1,a2,a3;
}a[100010];
bool ts1_cmp(node x,node y){
	return x.a1>y.a1;
}
void solve(){
	bool ts1=1;
	int n,pmax,ans=0;
	cin>>n;
	pmax=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		a[i].id=i;
		if(a[i].a2||a[i].a3) ts1=0;
	}
	if(ts1){//5 
		sort(a+1,a+n+1,ts1_cmp);
		for(int i=1;i<=pmax;i++){
			ans+=a[i].a1;
		}
		cout<<ans;
		return ;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

