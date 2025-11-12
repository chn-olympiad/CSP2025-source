#include<bits/stdc++.h>
#define int long long
using namespace std;
struct fish{
	string s,t;
}a[200005];
vector<int>qzhs(string s){
	vector<int>ret;
	ret.push_back(0);
	for(int i=1;i<s.size();i++){
		int flc=ret[i-1];
		while(flc&&s[flc]!=s[i])flc=ret[flc-1];
		if(s[flc]==s[i])ret.push_back(flc+1);
		else ret.push_back(0);
	}
	return ret;
}
vector<int>kmp(string s,string t){
	string flc=t+'%'+s;
	vector<int>p=qzhs(flc);
	vector<int>ret;
	for(int i=0;i<p.size();i++)
		if(p[i]==t.size())
			ret.push_back(i-t.size()*2);
	return ret;
}
void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i].s>>a[i].t;
	while(q--){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		int mn=1e18,mx=-1e18;
		for(int i=0;i<s.size();i++)
		if(s[i]!=t[i])
		mn=min(mn,i),mx=max(mx,i);
//		cout<<mn<<' '<<mx<<'\n';
		int ans=0;
		for(int ie=1;ie<=n;ie++){
//			cout<<a[ie].s.size()<<" "<<a[ie].s<<'\n';
			if(mx-mn+1>a[ie].s.size())continue;
			vector<int>p1=kmp(s,a[ie].s);
//			for(int i=0;i<p1.size();i++)
//			cout<<p1[i]<<' ';cout<<"&\n";
			if(p1.empty())continue;
			if(p1[0]>mn)continue;
			vector<int>p2=kmp(t,a[ie].t);
//			for(int i=0;i<p2.size();i++)
//			cout<<p2[i]<<' ';cout<<"!\n";
			if(p2.empty())continue;
			if(p2[0]>mn)continue;
			int ii=lower_bound(p1.begin(),p1.end(),mx-s.size()+1)-p1.begin()-1;
			int jj=lower_bound(p2.begin(),p2.end(),mx-s.size()+1)-p2.begin()-1;
//			cout<<ii<<' '<<jj<<"!!!!!!\n\n";
			for(;ii<p1.size()&&jj<p2.size()&&p1[ii]<=mn&&p2[jj]<=mn;ii++){
				while(jj<p2.size()&&p2[jj]<p1[ii])jj++;
				if(jj==p2.size())break;
				if(p2[jj]!=p1[ii])continue;
				ans++;
				break;
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}
/*
180 + 30 = 210pts -> \sqrt 7!
byd!

duo => s == t x
dan => s -> t

s != t

(x,y) max -> ans+1

tmd chuan chuan problem
where is manacher???
bai zhao tlb le /fad

WC gang hao you fu xi kmp
win!!!!!

25pts (?)

A = AC zi dong ji?

string killed flc.
100 + 80 + 25 + 12 = 217pts

in fact flc < 217pts

How can I get \sqrt 7?
*/
