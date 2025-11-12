#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,L=3e6+5;
const long long B=13331;
int n,q,num[N];
string t1,t2;
map<unsigned long long ,int>mp,mp2;
vector<int>p[N];
struct node{
	string s1,s2;
	int cl;
}a[N];
unsigned long long hs2[N],hs[N],pw[L];
long long w(char c1,char c2){
	long long res=0;
	res=26ll*c1+c2;
	return res;
}
bool cmp(node x,node y){
	return x.cl<y.cl;
}
unsigned long long ghs(int x,int y){
	return hs[y]-hs[x-1]*pw[y-x+1];
}
int find(int l,int r,int p2){
	int res=-1,ll=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mp2.count(ghs(ll,mid))) l=mid+1,res=mid;
		else r=mid-1;
	}
	if(res>=p2||res==-1||mp.count(ghs(ll,res))==0) return 0;
	return num[mp2[ghs(ll,res)]];
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<L;i++) pw[i]=pw[i-1]*B;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].cl=a[i].s1.size();
		hs2[i]=0;
		for(int j=0;j<a[i].cl;j++){
			hs2[i]=hs2[i]*B+w(a[i].s1[j],a[i].s2[j]);
			mp2.insert(make_pair(hs2[i],i));
			//if(hs2[i]==386655) cout<<i<<' '<<j<<"d\n\n";
		}
		mp[hs2[i]]++;
	}
	for(int i=1;i<=n;i++){
		unsigned long long now=0;
		for(int j=0;j<a[i].cl;j++){
			now=now*B+w(a[i].s1[j],a[i].s2[j]);
			if(mp.count(now)) num[i]+=mp[now];
		}
	}
	while(q--){
		long long ans=0;
		cin>>t1>>t2;
		int l=t1.size();
		hs[0]=w(t1[0],t2[0]);
		for(int i=1;i<l;i++) hs[i]=hs[i-1]*B+w(t1[i],t2[i]);
		int p1=-1,p2=-1;
		for(int i=0;i<l;i++){
			if(t1[i]!=t2[i]){
				p2=i;
				if(p1==-1) p1=i;
			}
		}
		for(int i=0;i<=p1;i++){
			for(int j=1;j<=n;j++){
				if(a[j].cl+i-1>=l) continue;
				
				if(hs2[j]==ghs(i,i+a[j].cl-1)&&i+a[j].cl-1>=p2) ++ans;
				//else cout<<i<<' '<<j<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
