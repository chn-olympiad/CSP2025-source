#include<bits/stdc++.h>
using namespace std;
#define ak ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqrt sqrtl
#define int long long
const int maxn=100005;
struct cl{int fi,se,th;}a[maxn];
struct pe{int v,_id;friend bool operator<(pe aa,pe bb){return aa.v<bb.v;}};
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	ak;
	cin>>T;
	while(T--){
		vector<pe> nod1,nod2,nod3,n11,n22,n33;
		int n,lim,s1=0,s2=0,s3=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se>>a[i].th;
		lim=n/2;
		for(int i=1;i<=n;i++){
			if(a[i].fi>=a[i].se&&a[i].fi>=a[i].th)nod1.push_back({a[i].fi,i});
			else if(a[i].se>=a[i].fi&&a[i].se>=a[i].th)nod2.push_back({a[i].se,i});
			else nod3.push_back({a[i].th,i});
		}
		for(auto ii:nod1)s1+=ii.v;
		for(auto ii:nod2)s2+=ii.v;
		for(auto ii:nod3)s3+=ii.v;
		if(nod1.size()<=lim&&nod2.size()<=lim&&nod3.size()<=lim){cout<<s1+s2+s3<<endl;continue;}
		for(int i=0;i<nod1.size();i++){
			int id1=nod1[i]._id;
			int leave=min(a[id1].fi-a[id1].se,a[id1].fi-a[id1].th);
			n11.push_back({leave,id1});
		}
		for(int i=0;i<nod2.size();i++){
			int id2=nod2[i]._id;
			int leave=min(a[id2].se-a[id2].fi,a[id2].se-a[id2].th);
			n22.push_back({leave,id2});
		}
		for(int i=0;i<nod3.size();i++){
			int id3=nod3[i]._id;
			int leave=min(a[id3].th-a[id3].se,a[id3].th-a[id3].fi);
			n33.push_back({leave,id3});
		}
		sort(n11.begin(),n11.end());reverse(n11.begin(),n11.end());
		sort(n22.begin(),n22.end());reverse(n22.begin(),n22.end());
		sort(n33.begin(),n33.end());reverse(n33.begin(),n33.end());
		while(n11.size()>lim){
			pe bc=n11.back();
			n11.pop_back();
			int idl=bc._id;
			if(a[idl].se>a[idl].th)n22.push_back({a[idl].se,idl});
			else n33.push_back({a[idl].th,idl});
		}
		while(n22.size()>lim){
			pe bc=n22.back();
			n22.pop_back();
			int idl=bc._id;
			if(a[idl].fi>a[idl].th)n11.push_back({a[idl].fi,idl});
			else n33.push_back({a[idl].th,idl});
		}
		while(n33.size()>lim){
			pe bc=n33.back();
			n33.pop_back();
			int idl=bc._id;
			if(a[idl].fi>a[idl].se)n11.push_back({a[idl].fi,idl});
			else n22.push_back({a[idl].se,idl});
		}
#define ____ cerr<<"ok"<<endl;
		for(int i=0;i<n11.size();i++){
			n11[i].v=a[n11[i]._id].fi;
		}
		for(int i=0;i<n22.size();i++){
			n22[i].v=a[n22[i]._id].se;
		}
		for(int i=0;i<n33.size();i++){
			n33[i].v=a[n33[i]._id].th;
		}
		s1=s2=s3=0;
		for(auto i:n11)s1+=i.v;
		for(auto i:n22)s2+=i.v;
		for(auto i:n33)s3+=i.v;
		cout<<s1+s2+s3<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

