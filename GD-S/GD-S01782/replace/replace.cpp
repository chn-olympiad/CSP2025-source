#include <bits/stdc++.h>
using namespace std;
const int N=2e5+55,M=5e6+66;
int n,Q,b[N][3],siz[N];
struct Node{
	string s1,s2;
}a[N];
string t1,t2;
//vector<int> h[M<<1];

bool cmp(const Node &x,const Node &y){
	return x.s1.size()<y.s1.size();
}

void solve(){
	int ans=0,mn=1e9+9,mx=0;
	for(int i=0;i<(int)t1.size();++i){
		if(t1[i]!=t2[i]) {
			mn=min(mn,i);
			mx=max(mx,i);
		}
	}
	for(int i=mx;i<(int)t1.size();++i){
		int pos=lower_bound(siz+1,siz+n+1,(i-mn+1))-siz;
		for(int j=pos;j<=n;++j){
			int t=a[j].s1.size();
			if(t>(i+1)) break;
			if(a[j].s1==t1.substr(i-t+1,t)&&a[j].s2==t2.substr(i-t+1,t)){
				++ans;
			}
		}
	}
	
	cout<<ans<<'\n';
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>Q;
//	bool flag=1;
	for(int i=1;i<=n;++i) {
		cin>>a[i].s1>>a[i].s2;
//		int cnta=0,cntb=0,b1i=0,b2i=0;
//		for(int j=0;j<(int)a[i].s1.size();++j){
//			if(a[i].s1[j]=='a') ++cnta;
//			else ++cntb,b1i=j;
//		}
//		flag&=(cnta+cntb==(int)a[i].s1.size()&&cntb==1);
//		
//		cnta=cntb=0;
//		for(int j=0;j<(int)a[i].s2.size();++j){
//			if(a[i].s2[j]=='a') ++cnta;
//			else ++cntb,b2i=j;
//		}
//		flag&=(cnta+cntb==(int)a[i].s2.size()&&cntb==1);
//		h[b1i-b2i+M].push_back(a[i].s1.size());
	}
	sort(a+1,a+n+1,cmp); 
	for(int i=1;i<=n;++i) siz[i]=a[i].s1.size(); 
	for(int _=1;_<=Q;++_){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			cout<<"0\n";
			continue;
		}
		solve();
//		if(!flag){
//			solve();
//			continue;
//		}
//		int cnta1=0,cntb1=0,b1i=0;
//		for(int j=0;j<(int)t1.size();++j){
//			if(t1[j]=='a') ++cnta1;
//			else ++cntb1,b1i=j;
//		}
//		
//		int cnta2=0,cntb2=0,b2i=0;
//		for(int j=0;j<(int)t2.size();++j){
//			if(t2[j]=='a') ++cnta2;
//			else ++cntb2,b2i=j;
//		}
//		if(flag&&cnta1+cntb1==(int)t1.size()&&cnta2+cntb2==(int)t2.size()&&cntb1==1&&cntb2==1){
//			int t=lower_bound(h[b1i-b2i+M].begin(),h[b1i-b2i+M].end(),t1.size())-h[b1i-b2i+M].begin();
//			cout<<(t+1)<<"\n";
//			continue;
//		}else solve();
	}
	return 0;
} 
