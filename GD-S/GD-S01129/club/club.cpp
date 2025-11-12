#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll=long long;

const int N = 1e5+8;
struct po{
	int a,b,c;
}s[N];

bool cmp1(po a,po b){
	if(a.a!=b.a) return a.a>b.a;
	else{
		int aa=max(a.b,a.c);
		int bb=max(b.b,b.c);
		return aa<bb;
	}
}
bool cmp2(po a,po b){
	if(a.b!=b.b) return a.b>b.b;
	else{
		int aa=max(a.a,a.c);
		int bb=max(b.a,b.c);
		return aa<bb;
	}
}
bool cmp3(po a,po b){
	if(a.c!=b.c) return a.c>b.c;
	else{
		int aa=max(a.b,a.a);
		int bb=max(b.b,b.a);
		return aa<bb;
	}
}

void solve(){
	int n;
	cin>>n;
	//vector<array<int,2>> ap,bp,cp;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
		//int aa=s[i].a,bb=s[i].b,cc=s[i].c;
//		if(max({aa,bb,cc})==aa) ap.push_back({aa,i});
//		if(max({aa,bb,cc})==bb) bp.push_back({bb,i});
//		if(max({aa,bb,cc})==cc) cp.push_back({cc,i});
	}
	
	ll umax=0,nn=n/2,ub,uc,ans=-1;
	
//	for(int i=0;i<nn;i++){
//		int aa=s[i].a,bb=s[i].b,cc=s[i].c;
//		if(aa>bb&&aa>cc){
//			
//		}
//	}
	sort(s,s+n,cmp1);
	for(int i=0;i<nn;i++){
		umax+=s[i].a;
	}
	for(int i=nn;i<n;i++){
		umax+=max(s[i].b,s[i].c);
	}
	ans=max(ans,umax);
	
	umax=0;
	sort(s,s+n,cmp2);
	for(int i=0;i<nn;i++){
		umax+=s[i].b;
	}
	for(int i=nn;i<n;i++){
		umax+=max(s[i].a,s[i].c);
	}
	ans=max(ans,umax);
	
	umax=0;
	sort(s,s+n,cmp3);
	for(int i=0;i<nn;i++){
		umax+=s[i].c;
	}
	for(int i=nn;i<n;i++){
		umax+=max(s[i].b,s[i].a);
	}
	ans=max(ans,umax);
	
	cout<<ans;
	return;
}

//Ren5Jie4Di4Ling5%
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}
