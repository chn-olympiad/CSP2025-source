#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node{
	LL v,num,clb;
};
LL t,n,c1,c2,c3,cntn,cnt[4],ans;
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		vector<node> a;
		bool vis[int(1e5)+5]={};
		memset(cnt,0,sizeof cnt);
		cntn=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c1>>c2>>c3;
			a.push_back({c1,i,1});
			a.push_back({c2,i,2});
			a.push_back({c3,i,3});
		}
		sort(a.begin(),a.end(),cmp);
		for(int i=0;i<a.size()&&cntn<n;i++){
			if(vis[a[i].num]||cnt[a[i].clb]>=n/2) continue;
			ans+=a[i].v;
			vis[a[i].num]=1;
			cntn++;
			cnt[a[i].clb]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
