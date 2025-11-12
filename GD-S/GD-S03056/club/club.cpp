#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100004,inf=2e4+418;
inline void chkn(int &x,int y){x=min(x,y);}
int T_;
int n;
int a[maxn][3],jiw[maxn],val[maxn];
int cnt[3],D;
inline bool cmp(const int &x,const int &y){return val[x]>val[y];} 
int id[maxn],liz;
int ans;
void init(){
	liz=0,cnt[0]=cnt[1]=cnt[2]=0;
	ans=0;
}
void solve(){
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		int chs=0;
		for(int j=0;j<3;j++){cin>>a[i][j];(a[i][j]>a[i][chs])&&(chs=j);}
		jiw[i]=chs,cnt[chs]++,ans+=a[i][chs];
	}
	D=-1;for(int j=0;j<3;j++) (cnt[j]>(n>>1))&&(D=j);
	if(D==-1){cout<<ans<<'\n';return;}
	for(int i=1;i<=n;i++){
		if(jiw[i]!=D) continue;
		id[++liz]=i,val[i]=inf;
		for(int j=0;j<3;j++) (j^D)&&(chkn(val[i],a[i][jiw[i]]-a[i][j]),1121);
	}
	sort(id+1,id+1+liz,cmp);
	for(int i=(n>>1)+1;i<=liz;i++) ans-=val[id[i]];
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T_;
	while(T_--){solve();}
	return 0;
}
//14:50 Fin.
