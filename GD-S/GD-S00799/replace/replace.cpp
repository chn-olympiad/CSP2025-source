#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define pui pair<ull,int>
#define mk(x,y) make_pair(x,y)
const int M=2e5+10,N=5e6+10;
const ull base=233;
int n,q;
int nxt[M];
map<ull,vector<pui>>mp;
string s[2][M];
int siz[M];
ull p[N];
vector<int>h[2][M];
int l[M],r[M];
ull th[2][N];
void build_hash_s(int x,int i){
	ull nh=s[x][i][0]-'a';
	h[x][i].push_back(nh);
	for(int j=1;j<siz[i];j++){
		nh=nh*base+s[x][i][j]-'a';
		h[x][i].push_back(nh);
	}
}
ull get_hash_s(int x,int i,int l,int r){
	int ll=r-l+1;
	ull hl;
	if(l==0)hl=0;
	else hl=h[x][i][l-1];
	return h[x][i][r]-hl*p[ll];
}
string t[2];
void build_hash_t(int x){
	int sz=t[x].size();
	th[x][0]=t[x][0]-'a';
	for(int i=1;i<sz;i++){
		th[x][i]=th[x][i-1]*base+t[x][i]-'a';
	}
}
ull get_hash_t(int x,int l,int r){
	int ll=r-l+1;
	ull tl;
	if(l==0)tl=0;
	else tl=th[x][l-1];
	return th[x][r]-tl*p[ll];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	p[0]=1;
	for(int i=1;i<N;i++)p[i]=p[i-1]*base;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
		siz[i]=s[0][i].size();
//		cout<<s[0][i]<<' '<<s[1][i]<<endl;
		build_hash_s(0,i);
		build_hash_s(1,i);
//		for(int j=0;j<siz[i];j++)cout<<h[0][i][j]<<' ';
//		cout<<endl;
//		for(int j=0;j<siz[i];j++)cout<<h[1][i][j]<<' ';
//		cout<<endl;
		l[i]=r[i]=-1;
		for(int j=0;j<siz[i];j++){
			if(s[0][i][j]!=s[1][i][j]){
				l[i]=j;
				break;
			}
		}
		for(int j=siz[i]-1;j>=0;j--){
			if(s[0][i][j]!=s[1][i][j]){
				r[i]=j;
				break;
			}
		}
		if(l[i]!=-1){
			ull ul=get_hash_s(0,i,l[i],r[i]),ur=get_hash_s(1,i,l[i],r[i]);
//			cout<<i<<' '<<l[i]<<' '<<r[i]<<' '<<ul<<' '<<ur<<endl;
			mp[ul].push_back(mk(ur,i));
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		int len=t[0].size();
		if(t[0].size()!=t[1].size())cout<<0<<endl;
		else{
			build_hash_t(0);
			build_hash_t(1);
			int ll=0,rr=0;
			for(int j=0;j<len;j++){
				if(t[0][j]!=t[1][j]){
					ll=j;
					break;
				}
			}
			for(int j=len-1;j>=0;j--){
				if(t[0][j]!=t[1][j]){
					rr=j;
					break;
				}
			}
//			cout<<"tt:"<<ll<<' '<<rr<<' '<<get_hash_t(0,ll,rr)<<' '<<get_hash_t(1,ll,rr)<<endl;
			ull ht=get_hash_t(0,ll,rr);
			if(mp.count(ht)){
				int ans=0;
				vector<pui>res=mp[ht];
				for(pui it:res){
					int id=it.second;
					ull nx=it.first;
					if(nx!=get_hash_t(1,ll,rr))continue;
					if(l[id]>ll||siz[id]-r[id]>len-rr)continue;
					if(get_hash_s(0,id,0,l[id])!=get_hash_t(0,ll-l[id],ll))continue;
					if(get_hash_s(0,id,r[id],siz[id]-1)!=get_hash_t(0,rr,rr+siz[id]-1-r[id]))continue;
					ans++;
				}
				cout<<ans<<endl;
			}else cout<<0<<endl;
		}
	}
	return 0;	
}
