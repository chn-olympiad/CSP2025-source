#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
int n,q,cnt1,cnt2,l1,l2,r1,r2,l,r,cc;
long long ans;
string s,t;
pair<int,int> x[200005],y[200005];
int c[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q==1){
		cout<<0;
		return 0;
	}
	for(int j=1;j<=n;++j){
		cin>>s>>t;
		cnt1=0,cnt2=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='b'){
				x[j].fi==cnt1;
				l=i;
				cnt1=-1;
			}
			if(t[i]=='b'){
				y[j].fi==cnt2;
				r=i;
				cnt2=-1;
			}
			++cnt1,++cnt2;
		}
		x[j].sc=cnt1,y[j].sc=cnt2,c[j]=r-l;
	}
	while(q--){
		ans=0;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<s.size();++i){
			if(s[i]=='b'){
				l1=cnt1;
				l=i;
				cnt1=-1;
			}
			if(t[i]=='b'){
				l2=cnt2;
				r=i;
				cnt2=-1;
			}
			++cnt1,++cnt2;
			r1=cnt1,r2=cnt2,cc=r-l;
		}
		for(int i=1;i<=n;++i){
			if(c[i]==cc){
				if(x[i].fi<=l1&&y[i].fi<=l2&&x[i].sc<=r1&&x[i].sc<=r2) ++ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
