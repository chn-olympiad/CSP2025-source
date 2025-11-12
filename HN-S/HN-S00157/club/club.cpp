#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define int long long
int T,n,ans,v[5],u[N];
struct nnn{
	int x,i,h;
}p[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,ph,gs,cbd,a,b,c;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)u[i]=0;
		v[1]=v[2]=v[3]=ans=0,ph=n/2;
		for(i=1;i<=n;i++){
			cin>>a>>b>>c;
			p[i].x=a,p[i+n].x=b,p[i+2*n].x=c;
			p[i].i=i,p[i+n].i=i,p[i+2*n].i=i;
			p[i].h=1,p[i+n].h=2,p[i+2*n].h=3;
		}if(n==2){
			ans=max(p[1].x+p[4].x,ans);
			ans=max(p[1].x+p[6].x,ans);
			ans=max(p[3].x+p[2].x,ans);
			ans=max(p[3].x+p[6].x,ans);
			ans=max(p[5].x+p[2].x,ans);
			ans=max(p[5].x+p[4].x,ans);
		}if(n==4){
			ans=max(p[1].x+p[2].x+p[11].x+p[12].x,ans);
			ans=max(p[1].x+p[2].x+p[7].x+p[8].x,ans);
			ans=max(p[1].x+p[2].x+p[11].x+p[8].x,ans);
			ans=max(p[1].x+p[2].x+p[7].x+p[12].x,ans);
			ans=max(p[1].x+p[3].x+p[6].x+p[12].x,ans);
			ans=max(p[1].x+p[3].x+p[6].x+p[8].x,ans);
			ans=max(p[1].x+p[3].x+p[10].x+p[12].x,ans);
			ans=max(p[1].x+p[3].x+p[10].x+p[8].x,ans);
			ans=max(p[1].x+p[4].x+p[6].x+p[7].x,ans);
			ans=max(p[1].x+p[4].x+p[6].x+p[11].x,ans);
			ans=max(p[1].x+p[4].x+p[10].x+p[7].x,ans);
			ans=max(p[1].x+p[4].x+p[10].x+p[11].x,ans);
			ans=max(p[2].x+p[4].x+p[5].x+p[7].x,ans);
			ans=max(p[2].x+p[4].x+p[5].x+p[11].x,ans);
			ans=max(p[2].x+p[4].x+p[9].x+p[7].x,ans);
			ans=max(p[2].x+p[4].x+p[9].x+p[11].x,ans);
			ans=max(p[3].x+p[4].x+p[5].x+p[6].x,ans);
			ans=max(p[3].x+p[4].x+p[5].x+p[10].x,ans);
			ans=max(p[3].x+p[4].x+p[9].x+p[6].x,ans);
			ans=max(p[3].x+p[4].x+p[9].x+p[10].x,ans);
			ans=max(p[3].x+p[2].x+p[7].x+p[6].x,ans);
			ans=max(p[3].x+p[2].x+p[11].x+p[6].x,ans);
			ans=max(p[3].x+p[2].x+p[11].x+p[10].x,ans);
			ans=max(p[3].x+p[2].x+p[7].x+p[10].x,ans);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
