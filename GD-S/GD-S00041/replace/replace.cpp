#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
const int N=5.2e6+10,base=29,mod=1e9+9,M=2e5+10;
// int stt;
struct st{
	int sn[26],v;
}tr1[N],tr2[N];
// int ed;
int idx1,idx2;
int n,q,lp,rp;
using ull=unsigned long long;
using pli=pair<ull,int>;
string x,y;
ull hsv1,hsv2;
using pll=pair<ull,ull>;
map<pll,int> rts;
pll tmp;
map<pll,vector<pair<string,string>>> mpt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	// cerr<<(&stt-&ed)/4.0/1024.0/1024.0<<'\n';
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		lp=0,rp=x.size()-1;
		while(lp<x.size() and x[lp]==y[lp])lp++;
		while(~rp and x[rp]==y[rp])rp--;
		if(lp>=x.size())continue;
		hsv1=hsv2=0;
		for(int j=lp;j<=rp;j++)hsv1=(hsv1*base+x[j]-'a')%mod,hsv2=(hsv2*base+y[j]-'a')%mod;
		tmp={hsv1,hsv2};
		mpt[tmp].emplace_back(x.substr(0,lp),y.substr(rp+1));
	}
	for(auto& i:mpt){
		// cout<<i.first.first<<' '<<i.first.second<<'\n';
		sort(i.second.begin(),i.second.end(),[&](pair<string,string>& p1,pair<string,string>& p2){return p1.first.size()<p2.first.size();});
		int crt=++idx1;
		rts[i.first]=crt;
		for(auto& j:i.second){
			int tbuf=crt;
			reverse(j.first.begin(),j.first.end());
			for(auto& k:j.first){
				if(!tr1[tbuf].sn[k-'a']){
					tr1[tbuf].sn[k-'a']=++idx1;
					tr1[idx1].v=tr1[tbuf].v;
				}
				tbuf=tr1[tbuf].sn[k-'a'];
			}
			// cout<<tbuf<<'\n';
			tr2[++idx2]=tr2[tr1[tbuf].v];
			tr1[tbuf].v=idx2;
			tbuf=idx2;
			for(auto& k:j.second){
				tr2[++idx2]=tr2[tr2[tbuf].sn[k-'a']];
				tr2[tbuf].sn[k-'a']=idx2;
				tbuf=idx2;
			}
			tr2[tbuf].v++;
		}
	}
	for(int i=1,res;i<=q;i++){
		cin>>x>>y;
		lp=0,rp=x.size()-1;
		while(lp<x.size() and x[lp]==y[lp])lp++;
		while(~rp and x[rp]==y[rp])rp--;
		hsv1=hsv2=0;
		for(int j=lp;j<=rp;j++)hsv1=(hsv1*base+x[j]-'a')%mod,hsv2=(hsv2*base+y[j]-'a')%mod;
		tmp={hsv1,hsv2};
		// cout<<hsv1<<' '<<hsv2<<'\n';
		int tbuf=rts[tmp];
		for(int j=lp-1;~j;j--){
			if(!tr1[tbuf].sn[x[j]-'a'])break;
			tbuf=tr1[tbuf].sn[x[j]-'a'];
		}
		tbuf=tr1[tbuf].v;
		if(!tbuf){
			cout<<0<<'\n';
			continue;
		}
		// cout<<"ok\n";
		res=tr2[tbuf].v;
		for(int j=rp+1;j<x.size();j++){
			if(!tr2[tbuf].sn[x[j]-'a'])break;
			tbuf=tr2[tbuf].sn[x[j]-'a'];
			res+=tr2[tbuf].v;
		}
		cout<<res<<'\n';
	}
}