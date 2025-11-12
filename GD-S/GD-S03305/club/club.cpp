#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,INF=2e9;
int T,n,cnt[5];
struct node{
	int val[5],id,d;
	inline bool operator<(const node &x)const{return d<x.d;} 
}a[N],b[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].val[1]>>a[i].val[2]>>a[i].val[3];
			int mx=max({a[i].val[1],a[i].val[2],a[i].val[3]});
			if(a[i].val[1]==mx)a[i].id=1;
			else if(a[i].val[2]==mx)a[i].id=2;
			else if(a[i].val[3]==mx)a[i].id=3;
			cnt[a[i].id]++,a[i].d=INF;
			for(int j=1;j<=3;j++){
				if(j==a[i].id)continue;
				a[i].d=min(a[i].d,a[i].val[a[i].id]-a[i].val[j]);
			}
			ans+=mx;
		}
		int tot=0;
		for(int i=1;i<=3;i++)
			if(cnt[i]>n/2){
				for(int j=1;j<=n;j++)if(a[j].id==i)b[++tot]=a[j];
				sort(b+1,b+tot+1);
				for(int j=1;j<=tot-n/2;j++)ans-=b[j].d;
				break;
			}
		cout<<ans<<'\n';
	}
	return 0;
}
