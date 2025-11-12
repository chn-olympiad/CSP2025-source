#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ma(a,b,c) make_pair(a,make_pair(b,c))
namespace yyh{
	int n;
	pair<int,int>t[100005][4];
	struct node{
		int a,b,c;
	}a[100005];
	priority_queue<pair<int,pair<int,int> > >cl[4];
	bool cmp(pair<int,int> x,pair<int,int> y){
		if(x.first!=y.first)return x.first>y.first;
		return cl[x.second].size()<cl[y.second].size();
	}
	int get(int k,int x){
		for(int i=x+1;i<=3;i++)
			if(cl[t[k][i].second].size()!=n/2)return i;
	}
	void solve(){
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		int ans=0;
		for(int i=1;i<=3;i++)
			while(!cl[i].empty())cl[i].pop();
		for(int i=1;i<=n;i++){
			t[i][1]=make_pair(a[i].a,1);
			t[i][2]=make_pair(a[i].b,2);
			t[i][3]=make_pair(a[i].c,3);
			sort(t[i]+1,t[i]+3+1,cmp);
			for(int j=1;j<=3;j++){
				if(cl[t[i][j].second].size()!=n/2){
//					cout<<t[i][get(i,j)].first-t[i][j].first<<endl;
					cl[t[i][j].second].push(ma((t[i][get(i,j)].first-t[i][j].first),i,j));
					ans+=t[i][j].first;
					break;
				}else{
					int p=get(i,j);
					pair<int,pair<int,int> >tmp=cl[t[i][j].second].top();
					int q=get(tmp.second.first,tmp.second.second);
					if(t[i][j].first>t[i][p].first-tmp.first){
						cl[t[i][j].second].pop();
						cl[t[i][j].second].push(ma((t[i][get(i,j)].first-t[i][j].first),i,j));
						cl[t[i][q].second].push(ma((t[tmp.second.first][get(tmp.second.first,q)].first-t[tmp.second.first][q].first),tmp.second.first,q));
//						cout<<ans<<endl<<t[i][j].first<<' '<<tmp.first<<endl;
						ans=ans+t[i][j].first+tmp.first;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	signed main(){
		int t;
		cin>>t;
		while(t--)solve();
		return 0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	yyh::main();
	return 0;
}
