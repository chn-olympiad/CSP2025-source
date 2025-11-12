#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
const int N=2e5+10;
int T,n,ans,mx,x,t,st[N],cnt[N],a[N][3],p[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n; ans=cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;++i){
			mx=-1;
			for(int j=0;j<3;++j){
				cin>>x; a[i][j]=x;
				if(x>mx) mx=x,p[i]=j;
			}
			++cnt[p[i]],ans+=mx;
		}
		if(cnt[0]>n/2){
			t=0;
			for(int i=1;i<=n;++i)
				if(p[i]==0) st[++t]=a[i][0]-max(a[i][1],a[i][2]);
			sort(st+1,st+t+1);
			for(int i=1;i<=cnt[0]-n/2;++i) ans-=st[i];
		}
		else if(cnt[1]>n/2){
			t=0;
			for(int i=1;i<=n;++i)
				if(p[i]==1) st[++t]=a[i][1]-max(a[i][2],a[i][0]);
			sort(st+1,st+t+1);
			for(int i=1;i<=cnt[1]-n/2;++i) ans-=st[i];
		}
		else if(cnt[2]>n/2){
			t=0;
			for(int i=1;i<=n;++i)
				if(p[i]==2) st[++t]=a[i][2]-max(a[i][0],a[i][1]);
			sort(st+1,st+t+1);
			for(int i=1;i<=cnt[2]-n/2;++i) ans-=st[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
