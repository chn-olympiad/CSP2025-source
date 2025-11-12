#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
int a[N][4],ct[4],tt[4];
bool vis[N];
struct anode{int x,id;bool operator < (const anode &oth)const{return x>oth.x;}}b[4][N];
int q[4][N],ot[4];
int tmp[N];
inline void sol(){
	cin>>n;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			b[j][i]=(anode){a[i][j],i};
		}
	}
	for(int i=1;i<=3;i++){
		sort(b[i]+1,b[i]+n+1);
		ct[i]=ot[i]=0,tt[i]=1;	
	}
	int ans=0,al=n;
	while(al>0){
		for(int i=1;i<=3;i++) while(tt[i]<=n&&vis[b[i][tt[i]].id]) tt[i]++;
		anode res={0,0};
		int qwq=0;
		for(int i=1;i<=3;i++) if(tt[i]<=n&&b[i][tt[i]]<res) res=b[i][tt[i]],qwq=i;
		int id=res.id,val=res.x;
		ct[qwq]++;
		vis[id]=1;al--;
		q[qwq][++ot[qwq]]=id;
		ans+=val;
		tt[qwq]++;
	} 
	int qwq=0;
	for(int i=1;i<=3;i++) if(ct[i]>n/2) qwq=i;
	if(!qwq){cout<<ans<<'\n';return;}
	for(int i=1;i<=ot[qwq];i++){
		int o=q[qwq][i];
		int res=0;
		for(int j=1;j<=3;j++) (j^qwq)&&(res=max(res,a[o][j]));
		tmp[i]=res-a[o][qwq];
	}
	sort(tmp+1,tmp+ot[qwq]+1);
	for(int i=ot[qwq];i>ot[qwq]-(ct[qwq]-n/2);i--) ans+=tmp[i];
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;cin>>T;
	while(T--) sol();
	return 0;
}

