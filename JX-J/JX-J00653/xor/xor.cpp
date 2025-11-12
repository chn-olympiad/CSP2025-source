#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define LL long long
int n;
const int N=5*1e5+10;
LL k,a[N];
LL sum[N];
unordered_map<LL,vector<int>>mp;
struct node{
	int l,r;
	bool vis;
};
bool cmp1(node x,node y){
	return x.l!=y.l?x.l<y.l:x.r>y.r;
}
bool cmp2(node x,node y){
	return x.l!=y.l?x.l<y.l:x.r<y.r;
}
vector<node>qj;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
		mp[sum[i]].push_back(i);
	}
    for(int i=1;i<=n;i++){
		LL l=k^sum[i-1];
		auto id=lower_bound(mp[l].begin(),mp[l].end(),i);
		if(id!=mp[l].end())qj.push_back({i,*id});
	}
	sort(qj.begin(),qj.end(),cmp1);
	int mx=INT_MAX;
	int len=qj.size();
	vector<bool>vis(len+2);
	int ans=0;//cout<<len<<"\n";
	//cout<<mp[1].size()<<"\n";
	for(int i=len-1;i>=0;i--){
		if(qj[i].r>=mx){
			qj[i].vis=1;
		}
		mx=min(mx,qj[i].r);
		//cout<<qj[i].l<<" "<<qj[i].r<<"\n";
	}
	mx=INT_MIN;
	ans=0;
	sort(qj.begin(),qj.end(),cmp2);
	for(int i=0;i<len;i++){
		if(qj[i].vis)continue;
		if(qj[i].l>mx){
			ans++;
			mx=qj[i].r;
		}
	}
	cout<<ans;
    return 0;
}
