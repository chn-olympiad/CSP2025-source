#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector <int> v;
int n,k,a[N],ans=0,pre[N],vis[4*N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	vis[0]=1;
	v.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=a[i]^pre[i-1];
		if(vis[pre[i]^k]){
			ans++;
			while(v.size()){
				vis[v[v.size()-1]]=0;
				v.pop_back();
			}
		}
		vis[pre[i]]=1;
		v.push_back(pre[i]);
	}
	cout<<ans;
	return 0;
} 