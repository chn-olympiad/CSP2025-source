// I Love CCF
// CSP-S 1=
// CSP-S 1=
// CSP-S 1=
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mkp make_pair
#define pll pair<ll,ll>
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int D=5000000;
int n,Q;
string a[200005],b[200005];
int d[200005],ra[200005],rb[200005];
int is_b(const string& s){
	int cnt=0,id=-1;
	rep(i,0,(int)s.size()-1){
		if(s[i]!='a'&&s[i]!='b')return -1;
		if(s[i]=='b'){
			if(cnt==1){
				return -1;
			}else{
				++cnt;id=i;
			}
		}
	}
	return id;
}
bool calc_b(const string& s,const string& t){
	int ret1=is_b(s);
	if(ret1==-1)return 0;
	int ret2=is_b(t);
	if(ret2==-1)return 0;
	int tmp=ret2-ret1;
	ll ans=0;
	rep(i,1,n){
		if(tmp!=d[i])continue;
		if(ret1+((int)a[i].size()-ra[i]-1)>=(int)s.size())continue;
		if(ret2+((int)b[i].size()-rb[i]-1)>=(int)t.size())continue;
		if(ret1-ra[i]<0)continue;
		if(ret2-rb[i]<0)continue;
		++ans;
	}
	cout<<ans<<'\n';
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	bool flagb=1;
	rep(i,1,n){
		cin>>a[i]>>b[i];
		if(!flagb)continue;
		int ret1=is_b(a[i]);
		if(ret1==-1)flagb=0;
		if(!flagb)continue;
		int ret2=is_b(b[i]);
		if(ret2==-1)flagb=0;
		d[i]=ret2-ret1;
		ra[i]=ret1;
		rb[i]=ret2;
//		++cnt[d[i]+D];
	}
	while(Q--){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<'\n';continue;
		}
		if(flagb){
			if(calc_b(s,t))continue;
		}
		ll ans=0;
		rep(i,1,n){
			if(a[i].size()>s.size())continue;
			rep(j,0,(int)(s.size()-a[i].size())){
				bool flag=1;
				rep(k,0,(int)a[i].size()-1){
					if(s[j+k]!=a[i][k]){
						flag=0;break;
					}
				}
				if(flag){
					bool flag2=1;
					rep(k,0,(int)s.size()-1){
						if(k<j){
							if(s[k]!=t[k]){
								flag2=0;break;
							}
						}else if(k<j+(int)a[i].size()){
							if(b[i][k-j]!=t[k]){
								flag2=0;break;
							}
						}else{
							if(s[k]!=t[k]){
								flag2=0;break;
							}
						}
					}
					if(flag2){
						++ans;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
// I Love CCF
