#include <bits/stdc++.h>
//#define int long long
#define debug(x) cout<<#x<<" = "<<x<<' '
#define N 100010
using namespace std;

struct TO{
	int one,two,thr,id;
}b[N];
bool cmp(TO a,TO b){
	return a.one > b.one;
}

int n,tot,ans,Mx,Mxc,pi;
int wt[N],ch1[N],ch2[N],cnt[N];
int a[N][5],Max[N];
bool vis[N];

void init(){
	cin>>n,Mx=n/2;
	cnt[1]=cnt[2]=cnt[3]=0,tot=ans=0;
	for(int i=1;i<=n;i++) Max[i]=vis[i]=0;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) Max[i]=max(Max[i],a[i][j]);
		for(int j=1;j<=3;j++)
			if(a[i][j] == Max[i])
				wt[i]=j;
		cnt[wt[i]]++;
	} //want and cnt
	
	Mxc=max(cnt[1],max(cnt[2],cnt[3]));
	if(cnt[1] == Mxc) pi=1;
	if(cnt[2] == Mxc) pi=2;
	if(cnt[3] == Mxc) pi=3; //Find max cnt
	
	for(int i=1;i<=n;i++)
		if(wt[i] == pi)
			b[++tot]={a[i][1],a[i][2],a[i][3],i}; //special
	
	sort(b+1,b+1+tot,cmp);
}

int Solve(int id){
	int p1,p2;
	if(id == 1) p1=2,p2=3;
	if(id == 2) p1=1,p2=3;
	if(id == 3) p1=1,p2=2; //other
	
	for(int i=1;i<=Mx;i++) vis[b[i].id]=1;
	for(int i=1;i<=n;i++){
		if(wt[i] == id && !vis[i]) ans+=max(a[i][p1],a[i][p2]);
		else ans+=Max[i];
	} //common
	
	int tot1=0,tot2=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) ch1[++tot1]=max(a[i][p1],a[i][p2])-a[i][id];
		else ch2[++tot2]=a[i][id]-max(a[i][p1],a[i][p2]);
	}
	sort(ch1+1,ch1+tot1+1,greater<int>()),sort(ch2+1,ch2+tot2+1,greater<int>());
	
	for(int i=1,r=1;i<=tot1;i++){
		if(ch1[i]+ch2[r] >= 0) ans+=ch1[i]+ch2[r],r++;
		else break;
	} //change
	
	return ans;
}

int solve(){
	if(Mxc >= Mx) return Solve(pi);
	else{
		for(int i=1;i<=n;i++)
			ans+=Max[i];
		return ans;
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int T=1;cin>>T;
	while(T--){
		init();
		cout<<solve()<<"\n";
	}
	return 0;
}
