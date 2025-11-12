#include<bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int n,m,k,ans=1e9+10;
struct node{
	int x,y,z;
}a[N];
bool cmp(node aa,node b){return aa.z<b.z;}
signed main(){

	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	int pd=1;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		ans=min(ans,x);
		for(int j=1;j<=n;j++){
			cin>>x;
			if(x!=0)pd=0;
		} 
	}
	if(pd)
		cout<<ans;
	else{
		sort(a+1,a+n+1,cmp);
		ans=0;
		for(int i=1;i<n;i++){
			ans+=a[i].z;
		}
	}
	
	cout<<ans;
	
	return 0;
}

