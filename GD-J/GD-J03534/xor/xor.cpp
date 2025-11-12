#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],pre[500005],maxx[500005],ans;
int last[2097152];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]^a[i];
	vector<pair<int,int> >v,cop;
	memset(last,-1,sizeof(last));
	last[0]=0;
	for(int i=1;i<=n;i++){
		if(last[pre[i]^k]!=-1) v.push_back({last[pre[i]^k]+1,i});
		last[pre[i]]=i;
	}
	sort(v.begin(),v.end());
	int minn=4e17;
	if(v.size()>0) for(int i=v.size()-1;i>=0;i--){
		if(v[i].second<minn) cop.push_back(v[i]);
		minn=min(minn,v[i].second);
	}
	sort(cop.begin(),cop.end());
	int k=0;
	for(int i=0;i<cop.size();i++){
		while(k<cop[i].second) k++,maxx[k]=max(maxx[k-1],maxx[k]);
		maxx[k]=max(maxx[k],maxx[cop[i].first-1]+1);
		ans=max(ans,maxx[k]);
	}
	cout<<ans;
	return 0;
}
