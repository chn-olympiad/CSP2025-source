#include<bits/stdc++.h>
#define int long long
#define mod 100000000000000003
using namespace std;
int n,Q,v[400005],p[400005],q[400005],ip[400005],iq[400005],u[400005],ans[400005];
string s[400005],t[400005];
vector<int>L[400005],R[400005],w[400005];
void add(int x,int v){
	for(;x<=4e5;x+=x&-x) u[x]+=v;
}
int que(int x,int v=0){
	for(;x;x-=x&-x) v+=u[x];
	return v;
}
int sh(int h,char x){
	return (h*31+x-'a'+1)%mod;
}
void chk(string A,string B,int&h,vector<int>&L,vector<int>&R){
	int m=A.size(),l=m,r=0;
	if(m!=B.size()) return h=-1,void();
	for(int i=0;i<m;i++) if(A[i]!=B[i]) l=min(l,i),r=max(r,i);
	if(l>r) return h=-1,void();
	for(int i=l;i<=r;i++) h=sh(sh(h,A[i]),B[i]);
	int z=0;
	for(int i=l-1;i>=0;i--) L.push_back(z=sh(z,A[i]));
	z=0;
	for(int i=r+1;i<m;i++) R.push_back(z=sh(z,A[i]));
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	int stoakioiorz=n+Q;
	for(int i=1;i<=stoakioiorz;i++) cin>>s[i]>>t[i],chk(s[i],t[i],v[i],L[i],R[i]),p[i]=q[i]=i;
	auto cmp=[&](int x,int y){
		if(v[x]!=v[y]) return v[x]<v[y];
		if(v[x]==-1) return x<y;
		int l=0,r=min(L[x].size(),L[y].size()),z=r;
		while(l<r){
			int mid=l+r>>1;
			if(L[x][mid]==L[y][mid]) l=mid+1;
			else r=mid;
		}
		if(l==z) return L[x].size()<L[y].size();
		return L[x][l]<L[y][l];
	};
	sort(p+1,p+n+Q+1,cmp);
	for(int i=1;i<=n+Q;i++) swap(L[i],R[i]);
	sort(q+1,q+n+Q+1,cmp);
	for(int i=1;i<=n+Q;i++) swap(L[i],R[i]);
	for(int i=1;i<=n+Q;i++) ip[p[i]]=i,iq[q[i]]=i;
	for(int i=1;i<=n;i++){
		int l=1,r=ip[i],A,B,C,D;
		if(v[i]==-1) continue; 
		auto chk=[&](int x,int*f,vector<int>*U){
			return v[f[x]]==v[i]&&U[f[x]].size()>=U[i].size()&&(!U[i].size()||U[f[x]][U[i].size()-1]==U[i].back());
		};
		while(l<r){
			int mid=l+r>>1;
			if(chk(mid,p,L)) r=mid;
			else l=mid+1;
		}
		A=l,l=ip[i],r=n+Q;
		while(l<r){
			int mid=l+r+1>>1;
			if(chk(mid,p,L)) l=mid;
			else r=mid-1;
		}
		B=l,l=1,r=iq[i];
		while(l<r){
			int mid=l+r>>1;
			if(chk(mid,q,R)) r=mid;
			else l=mid+1;
		}
		C=l,l=iq[i],r=n+Q;
		while(l<r){
			int mid=l+r+1>>1;
			if(chk(mid,q,R)) l=mid;
			else r=mid-1;
		}
		D=l;
		w[A].push_back(C),w[A].push_back(-D-1);
		w[B+1].push_back(-C),w[B+1].push_back(D+1);
	}
	for(int i=1;i<=n+Q;i++){
		for(int j:w[i]) add(abs(j),j>0?1:-1);
		if(p[i]>n) ans[p[i]-n]=que(iq[p[i]]);
	}
	for(int i=1;i<=Q;i++) printf("%lld\n",ans[i]);
	int ak=1919810,ioi=114514,bx=33550336;
	return (ak-ioi)/bx/bx/bx;
}
