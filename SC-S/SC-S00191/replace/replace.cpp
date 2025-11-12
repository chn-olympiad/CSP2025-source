#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=5e6+6,mod=998244353,INF=2e9;
#define rep(i,l,r)	for(int i=(l);i<=(r);i++)
#define atrep(i,l,r)	for(int i=(r);i>=(l);i--)
bool Meg;
const ull PP=131;
ull P[N];
ull hsL[N],hsR[N];
ull hsh(ull hs[],int l,int r){
	if(l>r)	return 0;
	return hs[r]-hs[l-1]*P[r-l+1];
}
string x[N],y[N];
ull get_hsh(string str){
	int now=str.size()-1;
	ull res=0;
	rep(i,1,now){
		res=res*PP+(str[i]-'a'+1);
	}
	return res;
}
int n,q;
ull HH[N],RO[N];
namespace subtask{
	void solve(){
		string p,q;
		cin>>p>>q;
		int sz=p.size();
		p=" "+p;
		q=" "+q;
		const int Len=10;
		map<pair<ull,ull>,vector<int>>bo;
		rep(j,1,sz)	hsL[j]=hsL[j-1]*PP+(p[j]-'a'+1);
		rep(j,1,sz)	hsR[j]=hsR[j-1]*PP+(q[j]-'a'+1);
		if(sz>=Len){
			rep(i,1,sz-Len+1){
				int l=i,r=i+Len-1;
				bo[{hsh(hsL,l,r),hsh(hsR,l,r)}].push_back(l);
			}	
		}
		int res=0;
		rep(i,1,n){
			if(x[i].size()<Len){
				int popin=x[i].size()-1;
				rep(k,1,sz-popin+1){
					int ll=k,rr=k+popin-1;
//					cout<<ll<<" "<<rr<<endl;
					ull L=hsh(hsL,ll,rr);
					ull R=hsh(hsR,ll,rr);
					if(hsh(hsR,1,ll-1)!=hsh(hsL,1,ll-1)||hsh(hsR,rr+1,sz)!=hsh(hsL,rr+1,sz)){
						continue;
					}
					if(L==RO[i]&&R==HH[i])
						res++;
				}
			}else{
				ull now1=0,now2=0;
				int qaq=x[i].size()-1;
				rep(o,1,Len){
					now1=now1*PP+(x[i][o]-'a'+1);
				}
				rep(o,1,Len){
					now2=now2*PP+(y[i][o]-'a'+1);
				}
				for(auto it:bo[{now1,now2}]){
					ull L=hsh(hsL,it,it+qaq-1);
					ull R=hsh(hsR,it,it+qaq-1);
					if(hsh(hsR,1,it-1)!=hsh(hsL,1,it-1)||hsh(hsR,it+qaq,sz)!=hsh(hsL,it+qaq,sz)){
						continue;
					}
					if(L==RO[i]&&R==HH[i])
						res++;
				}
			}
		}
		cout<<res<<endl;
	}
}
bool Beg;
int main(){
//	cerr<<(&Meg-&Beg)/1024.0/1024.0<<endl;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);	
	cin>>n>>q;
	const int Lim=5e6;
	P[0]=1;
	rep(i,1,Lim)	P[i]=P[i-1]*PP;
	map<pair<ull,ull>,int>mp;
	rep(i,1,n){
		cin>>x[i]>>y[i];
		x[i]=" "+x[i],y[i]=" "+y[i];
		RO[i]=get_hsh(x[i]),HH[i]=get_hsh(y[i]);
		mp[{get_hsh(x[i]),get_hsh(y[i])}]++;
	}
	if(q==1){
		subtask::solve();
		return 0;
	}
	rep(i,1,q){
		string p,q;
		cin>>p>>q;
		p=" "+p,q=" "+q;
		int sz=p.size()-1;
		hsL[0]=0;
		hsR[0]=0;
		rep(j,1,sz)	hsL[j]=hsL[j-1]*PP+(p[j]-'a'+1);
		rep(j,1,sz)	hsR[j]=hsR[j-1]*PP+(q[j]-'a'+1);
		int res=0;
		rep(j,1,sz){
			rep(k,1,j){
				ull L=hsh(hsL,k,j);
				ull R=hsh(hsR,k,j);
				if(hsh(hsR,1,k-1)!=hsh(hsL,1,k-1)||hsh(hsR,j+1,sz)!=hsh(hsL,j+1,sz)){
					continue;
				}
				res+=mp[{L,R}];
			}
		}
		cout<<res<<"\n";
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/