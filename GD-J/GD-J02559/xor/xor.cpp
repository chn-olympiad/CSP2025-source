#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],sum[N];
int vis[(1<<20)];
vector<pair<int,int> >v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	memset(vis,-1,sizeof vis);
	vis[0]=0;
	for(int i=1;i<=n;i++){
		int j=sum[i]^m;
		if(vis[j]!=-1)v.push_back({i,vis[j]+1});
		vis[sum[i]]=i;
	}
	sort(v.begin(),v.end());
	int lst=0,cnt=0;
	for(int i=0;i<(int)v.size();i++){
		if(lst<v[i].second){
			cnt++;
			lst=v[i].first;
		}
	}
	cout<<cnt;
	return 0;
}
