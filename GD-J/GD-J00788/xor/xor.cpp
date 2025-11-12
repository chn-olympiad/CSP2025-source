#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum,vis[500010];
int f(int l,int r){
	int ans=a[l];
	for(int i=l;i<r;i++)ans^=a[i+1];
	return ans;
}
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second-a.first<b.second-b.first;
}
vector<pair<int,int>> b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(i,j)==k)b.push_back({i,j});
		}
	}
	sort(b.begin(),b.end(),cmp);
	for(auto R:b){
		bool flag=0;
		for(int i=R.first;i<=R.second;i++)if(vis[i])flag=1;
		if(flag)continue; 
		for(int i=R.first;i<=R.second;i++)vis[i]=1;
		sum++;
		/*cout<<R.first<<','<<R.second<<' ';
		for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
		cout<<endl;*/
	}
	cout<<sum;
	return 0;
} 
