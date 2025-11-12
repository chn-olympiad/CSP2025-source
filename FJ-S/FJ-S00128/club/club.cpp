#include <bits/stdc++.h>
using namespace std;
struct p{
	int mx,cz;
};
bool cmp(p x,p y){
	return x.cz<=y.cz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while(T--){
		int n,ans=0;
		vector<p> t,g,h;
		cin>>n;
		for(int i=1,a,b,c;i<=n;i++){
			cin>>a>>b>>c;
			ans+=max(max(a,b),c);
			if(a>=b&&b>=c)
				t.push_back(p{a,a-b});
			else if(a>=c&&c>=b)
				t.push_back(p{a,a-c});
			else if(b>=a&&a>=c)
				g.push_back(p{b,b-a});
			else if(b>=c&&c>=a)
				g.push_back(p{b,b-c});
			else if(c>=a&&a>=b)
				h.push_back(p{c,c-a});
			else if(c>=b&&b>=a)
				h.push_back(p{c,c-b});
		}
		int cnt=0;
		if(t.size()*2>n){
			int k=t.size()-n/2;
			sort(t.begin(),t.end(),cmp);
			for(int i=0;i<k;i++){
				cnt+=t[i].cz;
			}
		}else if(g.size()*2>n){
			int k=g.size()-n/2;
			sort(g.begin(),g.end(),cmp);
			for(int i=0;i<k;i++){
				cnt+=g[i].cz;
			}
		}else if(h.size()*2>n){
			int k=h.size()-n/2;
			sort(h.begin(),h.end(),cmp);
			for(int i=0;i<k;i++){
				cnt+=h[i].cz;
			}
		}
		cout<<ans-cnt<<"\n";
	}
	return 0;
}
