#include <bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define endl '\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define pll pair<long long,long long>
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define mkp make_pair
//#define int long long
using namespace std;
using ll=long long;
using lld=long double;
const int N=1e5+10;
int T,n,a[N][5],clr[N],c[5];
ll ans;
int rmx(int i,int j){
	if(j==1)return max(a[i][2],a[i][3]);
	if(j==2)return max(a[i][1],a[i][3]);
	if(j==3)return max(a[i][1],a[i][2]);
	return -1;
}
int rmxi(int i,int j){
	if(j==1)return a[i][2]>a[i][3]?2:3;
	if(j==2)return a[i][1]>a[i][3]?1:3;
	if(j==3)return a[i][1]>a[i][2]?1:2;
	return -1;
}
struct node{
	int x,y,i;
}p[N];
bool cmp(node a,node b){
	return (a.x-a.y)<(b.x-b.y);
}
void solve(){
	ans=0,c[1]=c[2]=c[3]=0,cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int mx=max(a[i][1],max(a[i][2],a[i][3]));
		for(int j=1;j<=3;j++)
			if(a[i][j]==mx){
				clr[i]=j,c[j]++,ans+=(ll)mx;
				break;
			}
	}
	for(int j=1;j<=3;j++)if(c[j]>(n>>1)){
		for(int i=1,t=0;i<=n;i++)
			if(clr[i]==j)p[++t]={a[i][j],rmx(i,j),i};
		sort(p+1,p+c[j]+1,cmp);
		for(int i=1;i<=c[j]-(n>>1);i++)c[rmxi(p[i].i,j)]++,ans-=(ll)(p[i].x-p[i].y);
		break;
	}
	cout<<ans<<endl;
}
signed main(){
	FILE("club");
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(cin>>T;T--;solve());
	return 0;
}

