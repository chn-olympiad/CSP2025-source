#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c,k;
	inline bool operator<(node &A)const{
		return k>A.k;
	}
}t[N];
int T,n,cnt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;int ans=0;
		for (int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
			vector<int> p;
			p.push_back(t[i].a);
			p.push_back(t[i].b);
			p.push_back(t[i].c);
			sort(p.begin(),p.end());
			t[i].k=p[2]-p[1];
			ans+=t[i].a+t[i].b+t[i].c;
		}sort(t+1,t+n+1);
		ans=cnt[0]=cnt[1]=cnt[2]=0;
		for (int i=1;i<=n;i++){
			vector<pair<int,int> > p;
			p.push_back({t[i].a,0});
			p.push_back({t[i].b,1});
			p.push_back({t[i].c,2});
			sort(p.begin(),p.end(),greater<pair<int,int> >());
			for (int j=0;j<3;j++)
				if (cnt[p[j].second]<(n/2)){
					++cnt[p[j].second];
					ans+=p[j].first;
					break;
				}
		}cout<<ans<<'\n';
	}
	return 0;
}
