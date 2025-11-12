#include<bits/stdc++.h>
using namespace std;
#define mxn 500010
#define ll long long
#define pb push_back
#define pii pair<int,int>
ll f[210][210][210];
int n,a[mxn][4],num[mxn];
int check(){
	int id=2;
	for(int i=1;i<=n;i++){
		if(a[i][3]!=0)return 0;
		if(a[i][2]!=0)id=1;
	}
	return id;
}
void sol1(){
	for(int i=1;i<=n;i++)num[i]=a[i][1];
	sort(num+1,num+n+1);
	ll ans=0;
	for(int i=n;i>n/2;i--){
		ans+=num[i];
	}
	cout<<ans<<'\n';
	return;	
}
int c[mxn],mx[mxn];
int c1,c2;
void sol2(){
//	assert(0);
	ll ans=0;
	c1=0,c2=0;
	for(int i=1;i<=n;i++)mx[i]=0;
	for(int i=1;i<=n;i++){
		ans+=max(a[i][1],a[i][2]);
		if(a[i][1]<a[i][2])c[i]=a[i][2]-a[i][1],c1++;
		else c[i]=a[i][1]-a[i][2],c2++;
	}
	int frn=0;
	if(c1<c2)frn=n/2-c1;
	else frn=n/2-c2;
	sort(c+1,c+n+1);
	for(int i=1;i<=frn;i++)ans-=c[i];
	cout<<ans<<'\n';
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	int id=check();
	if(id==2){sol1();return;}
	else if(id==1){sol2();return;}
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=0,jt=min(i-1,n/2);j<=jt;j++)
			for(int k=max(0,i-1-j-n/2),kt=min(i-1-j,n/2);k<=kt;k++){
				int l=i-1-j-k;
				f[j+1][k][l]=max(f[j+1][k][l],f[j][k][l]+a[i][1]);
				f[j][k+1][l]=max(f[j][k+1][l],f[j][k][l]+a[i][2]);
				f[j][k][l+1]=max(f[j][k][l+1],f[j][k][l]+a[i][3]);
			}
	}
	ll ans=0;
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			for(int k=0;k<=n/2;k++)
				ans=max(ans,f[i][j][k]);
	cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
    int T;cin>>T;while(T--)solve();
    return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//#define mxn 500010
//#define ll long long
//#define pb push_back
//#define pii pair<int,int>
//int n,a[mxn][4],c;
//int s,t,val[mxn],fl[mxn];
//ll flp[mxn];
//ll maxc,maxf,dis[mxn];
//pii lst[mxn];
//bool inq[mxn];
//vector<pii> g[mxn];
//void addedge(int st,int ed,int v,int f){
//    g[st].pb({ed,++c});
//    val[c]=-v,fl[c]=f;
//    g[ed].pb({st,++c});
//    val[c]=v,fl[c]=0;
//}
//queue<int> q;
//bool spfa(){
//    for(int i=1;i<=t;i++)
//        dis[i]=1e16,inq[i]=0,flp[i]=1e16;
//    dis[s]=0,inq[s]=1,q.push(s);
//    while(!q.empty()){
//        int u=q.front();q.pop(),inq[u]=0;
////        cout<<u<<'\n';
////        for(auto [v,nm]:g[u]){
//		for(int i=0;i<g[u].size();i++){
//			pii& j=g[u][i];
//        	int v=j.first,nm=j.second;
////        	cout<<fl[nm]<<'\n';
//            if(!fl[nm])continue;
//            if(dis[v]>dis[u]+val[nm]){
//                dis[v]=dis[u]+val[nm];
//                flp[v]=min(flp[u],fl[nm]*1ll);
//                lst[v]={u,nm};
//                if(!inq[v])inq[v]=1,q.push(v);
//            }
//        }
//    }
////    cout<<dis[t]<<'\n';
//    if(dis[t]>=1e12)return 0;
//    return 1;
//}
//void dfs(){
//    int v=t;ll nflow=flp[t],cst=0;
//    while(v!=s){
//    	pii& i=lst[v];
//        int u=i.first,nm=i.second;
//        fl[nm]-=nflow,fl[nm^1]+=nflow;
//        cst+=nflow*val[nm];
//        v=u;
//    }
//    maxf+=nflow,maxc+=cst;
//}
//void ek(){while(spfa())dfs();}
//void solve(){
//    maxf=maxc=0;
//    cin>>n,c=1;
//    s=n+4,t=n+5;
//    for(int i=1;i<=n;i++){
//        cin>>a[i][1]>>a[i][2]>>a[i][3];
//        addedge(s,i,0,1);
//        addedge(i,n+1,a[i][1],1);
//        addedge(i,n+2,a[i][2],1);
//        addedge(i,n+3,a[i][3],1);
//    }
//    addedge(n+1,t,0,n/2);
//    addedge(n+2,t,0,n/2);
//    addedge(n+3,t,0,n/2);
//    ek();
//    for(int i=1;i<=t;i++)g[i].clear();
//    cout<<-maxc<<'\n';
//}
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0),cout.tie(0);
// 	freopen("club5.in","r",stdin);
// 	freopen("club.out","w",stdout);
//    int T;cin>>T;while(T--)solve();
//    return 0;
//}
////4
////4 2 1
////3 2 4
////5 3 4
////3 5 1

