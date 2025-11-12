#include<bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define rep1(i,s,t) for(int i=s;i<t;i++)
#define frep(i,s,t) for(int i=s;i>=t;i--)
#define frep1(i,s,t) for(int i=s;i>t;i++)
#define mset(ai,k) memset(ai,k,sizeof(ai))
using namespace std;
const int N=2e5+5;
int t,n,ai[N][3],f[3],x,ans;
struct node{
	int x,y;
}vi[N];
bool cmp(node a,node b){return a.y>b.y;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>t;
	while(t--){
		cin>>n;x=-1;ans=0;
		rep(i,0,2)f[i]=0;
		rep(i,1,n){
			cin>>ai[i][0]>>ai[i][1]>>ai[i][2];
			if(ai[i][0]>ai[i][1]&&ai[i][0]>ai[i][2])f[0]++;
			if(ai[i][1]>ai[i][0]&&ai[i][1]>ai[i][2])f[1]++;
			if(ai[i][2]>ai[i][0]&&ai[i][2]>ai[i][1])f[2]++;
		}
		if(f[0]>n/2)x=0;
		if(f[1]>n/2)x=1;
		if(f[2]>n/2)x=2;
		if(x==-1){
			rep(i,1,n)ans+=max(ai[i][0],max(ai[i][1],ai[i][2]));
		}
		else{
			rep(i,1,n)vi[i]=node{i,ai[i][x]-max(ai[i][(x+1)%3],ai[i][(x+2)%3])};
			sort(vi+1,vi+1+n,cmp);
			rep(i,1,n/2)ans+=vi[i].y;
			rep(i,1,n)ans+=max(ai[i][(x+1)%3],ai[i][(x+2)%3]);
		}
		cout<<ans<<endl;
	}
}
