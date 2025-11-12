/*
aaaabaaa
abaaaaaa


提示我们 t_1，t_2 不同的是一个区间

空间开得特别大，可以用二分+哈希+map 
*/
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,M=5e6+5;
const ull b=1331;
int n,Q;
//unordered_map<pair<ull,ull>,int>mp;
map<pair<ull,ull>,int>mp;
string s1[N],s2[N],t1,t2;
int len[N],id[N];
ull hs1[M],hs2[M],pw[M];
ull GetHash1(int x,int y) {
	return hs1[y]-hs1[x-1]*pw[y-x+1];
}
ull GetHash2(int x,int y) {
	return hs2[y]-hs2[x-1]*pw[y-x+1];
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>Q;
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*b;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
		id[i]=i;
		len[i]=s1[i].size();
	}
	sort(id+1,id+n+1,[=](const int &x,const int &y){
		return len[x]<len[y];
	});
	for(int i=1;i<=n;i++) {
 		int p=id[i];
		ull h1=0,h2=0;
		for(int j=0;j<len[p];j++) {
			ull nh1=h1*b+s1[p][j]+17;
			ull nh2=h2*b+s2[p][j]+31;
			if(!mp.count({nh1,nh2})) mp[{nh1,nh2}]=mp[{h1,h2}];
			h1=nh1,h2=nh2;
		}
		++mp[{h1,h2}];
	}
	while(Q--) {
		int res=0;
		cin>>t1>>t2;
		int m=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		hs1[0]=0;
		hs2[0]=0;
		for(int i=1;i<=m;i++) {
			hs1[i]=hs1[i-1]*b+t1[i]+17;
			hs2[i]=hs2[i-1]*b+t2[i]+31;
		}
		int lp=1,rp=m;
		while(t1[lp]==t2[lp]) ++lp;
		while(t1[rp]==t2[rp]) --rp;
		for(int i=1;i<=lp;i++) {
			int L=rp,R=m,ans=0;
			while(L<=R) {
				int mid=L+R>>1;
				if(mp.count({GetHash1(i,mid),GetHash2(i,mid)})) ans=mid,L=mid+1;
				else R=mid-1;
			}
			if(ans) res+=mp[{GetHash1(i,ans),GetHash2(i,ans)}]-mp[{GetHash1(i,rp-1),GetHash2(i,rp-1)}];
		}
		cout<<res<<"\n";
	}
	return 0;
}
/*
16:50 终于打完前三题暴力
*/ 
