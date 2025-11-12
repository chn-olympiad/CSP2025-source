//T3
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n,k;
int a[500007];
int d[500007],yhl[1048583],atd[500007];
vector<pii> v;
bool cmp(pii x,pii y)
{
	if(x.second==y.second) return x.first>y.first;
	return x.second<y.second;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int mx=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		d[i]=d[i-1]^a[i],mx=max(mx,a[i]);
	}
	for(int i=1;i<=1048576;++i){
		yhl[i]=-1;
	}
	for(int i=1;i<=n;++i){
		if(yhl[k^d[i]]!=-1){
			atd[i]=yhl[k^d[i]]+1;
		}
		yhl[d[i]]=i;
	}
//	for(int i=1;i<=n;++i){
//		cout<<d[i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;++i){
//		cout<<atd[i]<<" ";
//	}
	for(int i=1;i<=n;++i){
		if(atd[i]!=0){
			v.push_back({atd[i],i});
		}
	}
	sort(v.begin(),v.end(),cmp);
	int r=-114514,ans=0;
	for(int i=0;i<v.size();++i){
//		cout<<v[i].first<<" "<<v[i].second<<"\n";
		if(v[i].first>r){
			r=v[i].second,ans++;
		}
	}
	cout<<ans;
	return 0;
}
//2^20=1048576
//^^^^^^^^^^^^ 
