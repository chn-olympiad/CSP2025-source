#include<bits/stdc++.h>
#define int long long
using namespace std;
int xia[1050000]; 
int a[500010];
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first<b.first) return 1;
	if(a.second<b.second) return 1;
	return 0;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	vector< pair<int,int> > q;
	int n,k;
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=sum^a[i];
		if(sum==k) q.push_back({1,i});
		if(xia[sum^k]!=0) q.push_back({xia[sum^k]+1,i});
		xia[sum]=i;
	}
	sort(q.begin(),q.end());
//	cout<<q.size()<<endl<<endl<<endl;
//	for(int i=0;i<q.size();i++) cout<<q[i].first<<" "<<q[i].second<<endl;
	int r=-1;
	int ans=0;
//	cout<<endl<<endl;
	for(int i=0;i<q.size();i++){
		if(q[i].first<=r) continue;
		if(i<q.size()-1&&q[i+1].second<=q[i].second) continue;
		ans++,r=q[i].second;
	}
	cout<<ans;
	return 0;
}