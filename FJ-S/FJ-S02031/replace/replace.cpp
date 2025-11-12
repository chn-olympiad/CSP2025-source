#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans;
bool tb=true;
struct tbt{
	long long gap,f_front,f_last,b_front,b_last;
};
vector<tbt> tbs;
pair<string,string> a[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		int fb=a[i].first.find("b"),sb=a[i].second.find("b");
		if(tb){
			if(fb>a[i].first.size()||sb>a[i].first.size())tb=false;
			else{
				tbs.push_back({sb-fb,fb-1,a[i].first.size()-fb,sb-1,a[i].second.size()-sb});
			}
		}
	}
	while(q--){
		ans=0;
		string j1,j2;
		cin>>j1>>j2;
//		if(tb){
//			int b1=j1.find("b"),b2=j2.find("b");
//			for(tbt i:tbs){
//				if(i.gap==b2-b1&&b1-1>=i.f_front/*&&j1.size()-b1<=i.f_last&&b2-1>=i.b_front&&j1.size()-b2<=i.b_last*/){
//					ans++;
//				}
//			}
//		}
		else{
			for(int i=1;i<=n;i++){
				unsigned long long nmb=j1.find(a[i].first);
				if(nmb<=j1.size()){
					if(j1.substr(0,nmb)+a[i].second+j1.substr(nmb+a[i].first.size(),j1.size())==j2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
