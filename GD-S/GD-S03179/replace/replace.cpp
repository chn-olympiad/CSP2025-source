#include<bits/stdc++.h>
using namespace std;
#define int long long
void file(string fi){
	freopen((fi+".in").data(),"r",stdin);
	freopen((fi+".out").data(),"w",stdout);
} 
const int maxn=2e5+10,ba=113,mod=998244353,maxL=5e6+10;
int n,q;
int pw[maxL];
struct strh{
	string s;
	vector<int>hh;
	void push_back(char c){
		s+=c;
		if(hh.empty())hh.push_back(c);
		else hh.push_back((hh.back()*ba+c)%mod);
	}
	int geth(int l,int r){
		if(r>=s.size()||l<0)return 0;
		if(l==0)return hh[r];
		return (hh[r]-(hh[l-1]*pw[r-l+1]%mod)+mod)%mod;
	}
	void operator=(const string &r){
		s.clear();
		hh.clear();
		for(int i=0;i<r.size();++i)
			push_back(r[i]);
	}
};
string fr[maxn],to[maxn];
strh s1[maxn],s2[maxn];
signed main(){
	file("replace");
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>fr[i]>>to[i];
	for(int i=1;i<=n;++i)s1[i]=fr[i],s2[i]=to[i];
	pw[0]=1;
	for(int i=1;i<maxL;++i)pw[i]=(pw[i-1]*ba)%mod;
	while(q--){
		string t1,t2;cin>>t1>>t2;
		strh be,ed;
		be=t1,ed=t2;
		int ans=0;
		for(int i=1;i<=n;++i)
		if(fr[i].size()<=t1.size()){
			for(int j=0;j+fr[i].size()-1<t1.size();++j){
				if(be.geth(j,j+fr[i].size()-1)==s1[i].hh.back()){
					int l1=be.geth(0,j-1),l2=s2[i].hh.back(),l3=be.geth(j+fr[i].size(),t1.size()-1);
					int r1=ed.geth(0,j-1),r2=ed.geth(j,j+to[i].size()-1),r3=ed.geth(j+to[i].size(),t2.size()-1);
					if(l1==r1&&l2==r2&&l3==r3)++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
