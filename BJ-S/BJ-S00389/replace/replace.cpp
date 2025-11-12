#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;	
const ll MOD1=998244353;
const ll MOD2=1e9+7;
bool MEM_START;
pair<ll,ll>ghsh(string p){
	ll val1=0,val2=0;
	for(auto c:p){
		val1=val1*26%MOD1+c-'a';
		val2=val2*26%MOD2+c-'a';
		val1%=MOD1,val2%=MOD2;
	}
	return {val1,val2};
}
pair<pair<ll,ll>,pair<ll,ll>>hsh(string p,string q){
	return {ghsh(p),ghsh(q)};
}
pair<ll,ll>hsn[MAXN];
int n,q;
string sa[MAXN],sb[MAXN];
int loc[MAXN];
vector<int>id[MAXN];
int tptot;
map<pair<pair<ll,ll>,pair<ll,ll>>,int>tn;
int L[MAXN],R[MAXN];
int gl,gr;
int gid(string p,string q,bool ad){
	int l=-1,r=-2;
	string sl="",sr="";
	rep(j,0,int(p.size())-1){
		if(p[j]!=q[j]){
			l=r=j;
			rep(k,j,int(p.size())-1){
				if(p[k]!=q[k]){
					r=k;
				}
			};
			break;
		}
	};
	rep(j,l,r){
		sl+=p[j],sr+=q[j];
	};
	gl=l,gr=r;
	pair<pair<ll,ll>,pair<ll,ll>>sh=hsh(sl,sr);
	if(!tn.count(sh)){
		if(ad){
			tn[sh]=++tptot;
		}else{
			return -1;
		}
	}
	return tn[sh];
}
int TT;
namespace Baoli{
	pair<ll,ll>hnm[5000005];
	ll ksm(ll x,ll y,ll MOD){
		ll ans=1;
		while(y){
			if(y&1){
				ans=ans*x%MOD;
			}
			x=x*x%MOD;
			y>>=1;
		};
		return ans;
	};
	ll zz[2][5000005];
	void init(){
		zz[0][0]=zz[1][0]=1;
		rep(i,1,5000004){
			zz[0][i]=zz[0][i-1]*26%MOD1;
			zz[1][i]=zz[1][i-1]*26%MOD2;
		};
	};
	pair<ll,ll>gvh(int l,int r){
		if(l==0){
			return hnm[r];
		}
		ll fst=(hnm[r].first-hnm[l-1].first*zz[0][r-l+1]%MOD1+MOD1)%MOD1;
		ll sec=(hnm[r].second-hnm[l-1].second*zz[1][r-l+1]%MOD2+MOD2)%MOD2;
		return {fst,sec};
	};
	bool cmp(int x,int y){
		return L[x]<L[y];
	};
	int Do(string p,int tp){
		hnm[0]={0,0};
		rep(i,0,int(p.size())-1){
			if(i>0){
				hnm[i]=hnm[i-1];
			}
			hnm[i].first=hnm[i].first*26+(p[i]-'a');
			hnm[i].first%=MOD1;
			hnm[i].second=hnm[i].second*26+(p[i]-'a');
			hnm[i].second%=MOD2;
		}
		int ans=0;
		for(auto i:id[tp]){
			if(R[i]-L[i]!=gr-gl){
				continue;
			}
			bool gd=true;
			if(L[i]>gl){
				break;
			}
			if(int(sa[i].size())-L[i]>int(p.size())-gl){
				continue;
			}
			//~ pair<ll,ll>val={0,0};
			//~ rep(j,0,int(sa[i].size())-1){
				//~ val.first=(val.first*26%MOD1+(p[cg+j]-'a'))%MOD1;
				//~ val.first%=MOD1;
				//~ val.second=(val.second*26%MOD2+(p[cg+j]-'a'))%MOD2;
				//~ val.second%=MOD2;
			//~ };
			pair<ll,ll>rhs=gvh(gl-L[i],gl-L[i]+int(sa[i].size())-1);
			if(rhs!=hsn[i]){
				continue;
			}
			ans+=gd;
		}
		return ans;
	};
}
map<pair<pair<ll,ll>,pair<ll,ll>>,int>vs_ans;
bool MEM_END;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	Baoli::init();
	rep(i,1,n){
		cin>>sa[i]>>sb[i];
		hsn[i]=ghsh(sa[i]);
		loc[i]=gid(sa[i],sb[i],true);
		L[i]=gl,R[i]=gr;
		id[loc[i]].push_back(i);
	};
	rep(i,1,tptot){
		sort(id[i].begin(),id[i].end(),Baoli::cmp);
	};
	rep(i,1,q){
		string p,q;
		cin>>p>>q;
		int tp=gid(p,q,false);
		if(tp==-1){
			cout<<0<<"\n";
			continue;
		}
		pair<pair<ll,ll>,pair<ll,ll>> sh=hsh(p,q);
		if(vs_ans.count(sh)){
			cout<<vs_ans[sh]<<"\n";
			continue;
		}
		TT=i;
		int nm=Baoli::Do(p,tp);
		vs_ans[sh]=nm;
		cout<<nm<<"\n";
	};
	return 0;
}
