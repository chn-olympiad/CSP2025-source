#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
const int P=313;
struct nd{
	int l,r,len;
	ull lsum,rsum,to;
}e[N];
ull h[N];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	map<ull,set<int>> m;
	h[0]=1;
	for(int i=1;i<=n;i++) h[i]=h[i-1]*P;
	for(int i=1;i<=n;i++){
		string x,y;cin>>x>>y;
		ull sum=0;int l=-1,r=0;
		for(int j=0;j<x.size();j++){
			if(x[j]!=y[j]){
				if(l==-1) l=j;
				r=j;
			}
		}
		e[i].l=l,e[i].r=r,e[i].len=x.size();
		for(int j=0;j<l;j++) e[i].lsum=e[i].lsum*P+x[j];
		for(int j=l;j<=r;j++) sum=sum*P+x[j],e[i].to=e[i].to*P+y[j];
		for(int j=r+1;j<x.size();j++) e[i].rsum=e[i].rsum*P+x[j];
		m[sum].insert(i);
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) cout<<0<<"\n";
		else{
			ull s=0,ss=0;
			vector<ull> p(t1.size()+10,0);
			int l=-1,r=0,cnt=0;
			for(int i=0;i<t1.size();i++){
				if(t1[i]!=t2[i]){
					if(l==-1) l=i;
					r=i;
					s=s*P+t1[i];
					ss=ss*P+t2[i];
				}
				if(!i) p[i]=t1[i];
				else p[i]=p[i-1]*P+t1[i];
			}
			for(auto i:m[s]){
				if(!(l<e[i].l||t1.size()-r<e[i].len-e[i].r)){
					if(e[i].to!=ss) continue;
					if((!l||(p[l-1]-p[l-e[i].l-1]*h[e[i].l]==e[i].lsum)||(l-e[i].l==0&&p[l-1]==e[i].lsum))&&(r==t1.size()-1||p[r+e[i].len-e[i].r-1]-p[r]*h[e[i].len-e[i].r-1]==e[i].rsum)) cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
