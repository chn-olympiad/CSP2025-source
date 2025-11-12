#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t,ans;
struct E{
	ll a,b,c,ab,bc,ca,mx;
} e;
vector<E> qa,qb,qc;
bool cmp1(E xx,E yy){
	return min(abs(xx.ab),abs(xx.ca))>min(abs(yy.ab),abs(yy.ca));
}
bool cmp2(E xx,E yy){
	return min(abs(xx.ab),abs(xx.bc))>min(abs(yy.ab),abs(yy.bc));
}
bool cmp3(E xx,E yy){
	return min(abs(xx.ca),abs(xx.bc))>min(abs(yy.ca),abs(yy.bc));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		qa.clear();
		qb.clear();
		qc.clear();
		cin>>n;
		ans=0;
		for(ll i=1;i<=n;i++){
			cin>>e.a>>e.b>>e.c;
			e.ab=e.a-e.b;
			e.bc=e.b-e.c;
			e.ca=e.c-e.a;
			e.mx=max(e.a,max(e.b,e.c));
			if(e.mx==e.a) qa.emplace_back(e);
			else if(e.mx==e.b) qb.emplace_back(e);
			else qc.emplace_back(e);
		}
		if((qa.size()<=n/2&&qb.size()<=n/2)&&qc.size()<=n/2){
			for(ll i=0;i<qa.size();i++) ans+=qa[i].a;
			for(ll i=0;i<qb.size();i++) ans+=qb[i].b;
			for(ll i=0;i<qc.size();i++) ans+=qc[i].c;
			cout<<ans<<"\n";
			continue;
		}
		if(qa.size()>n/2){
			sort(qa.begin(),qa.end(),cmp1);
			for(ll i=0;i<n/2;i++){
				ans+=qa[i].a;
			}
			for(ll i=n/2;i<qa.size();i++){
				ans+=max(qa[i].b,qa[i].c);
			}
			for(ll i=0;i<qb.size();i++){
				ans+=qb[i].b;
			}
			for(ll i=0;i<qc.size();i++){
				ans+=qc[i].c;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(qb.size()>n/2){
			sort(qb.begin(),qb.end(),cmp2);
			for(ll i=0;i<n/2;i++){
				ans+=qb[i].b;
			}
			for(ll i=n/2;i<qa.size();i++){
				ans+=max(qb[i].a,qb[i].c);
			}
			for(ll i=0;i<qa.size();i++){
				ans+=qa[i].a;
			}
			for(ll i=0;i<qc.size();i++){
				ans+=qc[i].c;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(qc.size()>n/2){
			sort(qc.begin(),qc.end(),cmp3);
			for(ll i=0;i<n/2;i++){
				ans+=qc[i].c;
			}
			for(ll i=n/2;i<qc.size();i++){
				ans+=max(qc[i].a,qc[i].b);
			}
			for(ll i=0;i<qa.size();i++){
				ans+=qa[i].a;
			}
			for(ll i=0;i<qb.size();i++){
				ans+=qb[i].b;
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
