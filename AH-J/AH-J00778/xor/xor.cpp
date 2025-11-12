#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[5000001],xr[5000001],l,r,cnt=0,ans=0;
map<int,int> mp;
map<int,vector<int>> wh;
struct Node{
	int l,r;
}q[5000001];
bool cmp(Node x,Node y){
	return x.r<y.r;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	mp[0]++;
	wh[0].push_back(0);
	for(int i=1;i<=n;i++){
		xr[i]=xr[i-1]^a[i];
		mp[xr[i]]++;
		wh[xr[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			q[++cnt].l=i;
			q[cnt].r=i;
		}
		else if(mp[k^xr[i]]){
			for(int j=0;j<wh[k^xr[i]].size();j++){
				if(wh[k^xr[i]][j]<i)	
					q[++cnt].l=wh[k^xr[i]][j]+1,q[cnt].r=i;
			}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int l=0;
	for(int i=1;i<=cnt;i++){
		if(l<q[i].l){
			l=q[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
