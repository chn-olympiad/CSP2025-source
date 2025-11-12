#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const ll mod=100000000000000019,B=31;
int n,q;
string aa,bb,s,t[200010][3];
int tot;
vector<pair<char,int>> p[5000010];
unordered_map<ll,int> cnt[5000010],tmp;
struct node{
	int id,l,r;
};
vector<node> qr[5000010];
int ans[200010];
void insert(ll hsh){
	if(s==""){
		cnt[0][hsh]++;
		return ;
	}
//	cout<<s<<'\n';
	int now=0,len=s.size();
	for(int i=0;i<len;i++){
		int pp=-1;
		for(auto j:p[now]){
			if(j.first==s[i]){
				pp=j.second;
				break;
			}
		}
		if(pp==-1){
			p[now].push_back({s[i],++tot});
			pp=tot;
		}
//		if(!p[now][s[i]-'a']) p[now][s[i]-'a']=++tot;
		now=pp;
	}
	cnt[now][hsh]++;
}
void insert1(int id,int l,int r){
	if(s==""){
		qr[0].push_back({id,l,r});
		return ;
	}
	int now=0,len=s.size();
	for(int i=0;i<len;i++){
		int pp=-1;
		for(auto j:p[now]){
			if(j.first==s[i]){
				pp=j.second;
				break;
			}
		}
		if(pp==-1){
			qr[now].push_back({id,l,r});
			return ;
		}
		now=pp;
	}
	qr[now].push_back({id,l,r});
}
inline void work(ll &h,char aa,ll &mi){
	h=(h+(aa-'a'+1)*mi%mod)%mod;
	mi=mi*B%mod;
	return ;
}
void dfs(int u,int fa){
	for(auto i:cnt[u]) tmp[i.first]+=i.second;
	for(auto vv:qr[u]){
		int id=vv.id,l=vv.l,r=vv.r;
		ll h=0ll,mi=1ll;
		for(int i=r;i>l;i--){
			work(h,t[id][2][i],mi);
			work(h,t[id][1][i],mi);
		}
		for(int i=l;i>=0;i--){
			work(h,t[id][2][i],mi);
			work(h,t[id][1][i],mi);
			ans[id]+=tmp[h];
//			cout<<t[id][1]<<' '<<t[id][2]<<' '<<h<<"\n";
		}
	}
	for(auto vv:p[u]){
		int v=vv.second;
		if(!v) continue;
		dfs(v,u);
	}
	for(auto i:cnt[u]) tmp[i.first]-=i.second;
}
//int d[4]={7,9,17,19};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<=5000000;i++) p[i].shrink_to_fit();
//	ll mm=1ll;
//	for(int i=1;i<=12;i++) mm=mm*10ll;
//	for(int i=13;i<=17;i++){
//		mm=mm*10ll;
//		for(int j=0;j<4;j++){
//			ll ttt=mm+d[j];
//			bool flag=0;
//			for(ll i=2;i*i<=ttt;i++){
//				if(ttt%i!=0) continue;
//				flag=1;
//				break;
//			}
//			if(!flag) cout<<ttt<<'\n';
//		}
//	}
	for(int i=1;i<=n;i++){
		cin>>aa>>bb;
		int len=aa.size(),r=-1;
		for(int j=len-1;j>=0;j--){
			if(aa[j]==bb[j]) continue;
			r=j;break;
		}
//		if(aa=="l"&&bb=="y") cout<<r<<'\n';
		if(r==-1) continue;
		ll hsh=0ll;
		for(int j=0;j<=r;j++){
			hsh=(hsh*B%mod+(aa[j]-'a'+1))%mod;
			hsh=(hsh*B%mod+(bb[j]-'a'+1))%mod;
		}
//		if(aa=="l"&&bb=="y") cout<<hsh<<'\n';
		s="";
		for(int j=r+1;j<len;j++) s+=aa[j];
//		cout<<aa<<' '<<bb<<' '<<hsh<<'\n';
		insert(hsh);
	} 
	dfs(0,0);
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
//		if(i==16911) cout<<t[i][1]<<' '<<t[i][2]<<'\n';
		int len=t[i][1].size(),r=-1,l=-1;
		for(int j=len-1;j>=0;j--){
			if(t[i][1][j]==t[i][2][j]) continue;
			r=j;break;
		}
		for(int j=0;j<len;j++){
			if(t[i][1][j]==t[i][2][j]) continue;
			l=j;break;
		}
		s="";
		for(int j=r+1;j<len;j++) s+=t[i][1][j];
		insert1(i,l,r);
	}
	dfs(0,0);
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
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
