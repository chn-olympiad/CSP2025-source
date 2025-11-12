#include<bits/stdc++.h>
using namespace std;
int t,n,q,w,e;
struct p{
	pair<int,int> s[4];
}a[100010];
bool cmp(p x,p y){
	if(x.s[1].first!=y.s[1].first)return x.s[1].first>y.s[1].first;
	if(x.s[2].first!=y.s[2].first)return x.s[2].first>y.s[2].first;
	return x.s[3].first>y.s[3].first;
}
int main(){
        freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q>>w>>e;
			a[i].s[1]=make_pair(q,1);
			a[i].s[2]=make_pair(w,2);
			a[i].s[3]=make_pair(e,3);
			sort(a[i].s+1,a[i].s+4);
			reverse(a[i].s+1,a[i].s+4);
		}
		sort(a+1,a+n+1,cmp);
		/*
		for(int i=1;i<=n;i++){
			cerr<<"i="<<i<<' '<<a[i].s[1].first<<' '<<a[i].s[1].second<<a[i].s[2].first<<' '<<a[i].s[2].second<<a[i].s[3].first<<' '<<a[i].s[3].second<<endl;
		}
		*/
		int f[4]={0,0,0,0};
		bool tf[4]={0,1,1,1};
		vector<pair<pair<int,int>,pair<int,int> > >ff[4];
		bool flag2=0,flag1=0;
		for(int i=1;i<=n;i++){
			if(f[1]>=n/2)tf[1]=false;
			if(f[2]>=n/2)tf[2]=false;
			if(f[3]>=n/2)tf[3]=false;
			int xans=0;
			for(int i=1;i<=3;i++){
				if(!tf[i])xans++;
			}
			if(xans>=1)flag2=true;
			if(xans>=2)flag1=true;
			//cerr<<flag2<<' ';
			if(!flag2){
				f[a[i].s[1].second]++;
				ff[a[i].s[1].second].push_back(make_pair(make_pair(1,i),make_pair(a[i].s[1].first-a[i].s[2].first,a[i].s[2].first-a[i].s[3].first)));
				ans+=a[i].s[1].first;
				//cerr<<"ans="<<ans<<' ';
			}
			if(flag2){
				int w=0;
				for(int i=1;i<=3;i++){
					//cerr<<tf[i];
					if(!tf[i]){
						w=i;
						break;
					}
				}
				if(a[i].s[1].second!=w){
					//cerr<<"do";
					f[a[i].s[1].second]++;
                                	ff[a[i].s[1].second].push_back(make_pair(make_pair(1,i),make_pair(a[i].s[1].first-a[i].s[2].first,a[i].s[2].first-a[i].s[3].first)));
                                	ans+=a[i].s[1].first;
					//cerr<<"ans="<<ans<<'\n';
					continue;
				}
				sort(ff[w].begin(),ff[w].end());
				//cerr<<a[i].s[1].first-a[i].s[2].first<<' '<<ff[w][0].second.first<<endl;
				//cerr<<a[i].s[1].first-a[i].s[2].first;
				if(a[i].s[1].first-a[i].s[2].first>=ff[w][0].second.first){
					//cerr<<"do2";
					ff[w][0].first.first=2;
					ff[w][0].second.second=2000000000;
					ff[a[ff[w][0].first.second].s[2].second].push_back(ff[w][1]);
					f[a[ff[w][0].first.second].s[2].second]++;
					ff[w][0].first.first=100;
					ff[a[i].s[1].second].push_back(make_pair(make_pair(1,i),make_pair(a[i].s[1].first-a[i].s[2].first,a[i].s[2].first-a[i].s[3].first)));
					ans+=a[i].s[1].first-(ff[w][0].second.first);
					//cerr<<"ans="<<ans<<endl;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
