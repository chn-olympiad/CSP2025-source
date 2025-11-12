#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int vis[5010];
long long ans=0;
int sum[5010];
int smx[5010];
vector<int> v;
void dfs(int xb,int he,int mx){
    if(xb>=n){
        if(he>mx*2&&v.size()>=3){
            ans++;
            ans=ans%998244353;
        }
        return ;
    }
    dfs(xb+1,he,mx);
    if(vis[xb]==0){
        vis[xb]=1;
        v.push_back(a[xb]);
        dfs(xb+1,he+=a[xb],max(mx,a[xb]));
        if(!v.empty()){
            v.pop_back();
        }

        vis[xb]=0;
    }
    return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	dfs(0,0,0);
	ans=ans%998244353;
	cout<<ans;
	return 0;
}
