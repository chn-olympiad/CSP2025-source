#include <bits/stdc++.h>
#define N 100001
using namespace std;
struct Node{
	int val,i,j;
	bool operator<(const Node &b)const{return val>b.val;}
}b[N*2];
int t,n,tot,ans,p1,p2,p3,i;
int a[N][4],cnt[4];
bool vis[N];
void solve(){
	cin>>n;
	tot=ans=0;
	for (i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		b[++tot]={a[i][2]-a[i][1],i,2},b[++tot]={a[i][3]-a[i][1],i,3};
		ans+=a[i][1];
	}
	sort(b+1,b+tot+1);
	cnt[2]=cnt[3]=0,cnt[1]=n;
	memset(vis,0,sizeof vis);
	for (i=1;i<=tot&&(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2);i++){
		if (!vis[b[i].i]&&cnt[b[i].j]<n/2&&cnt[1]){
			cnt[b[i].j]++,cnt[1]--;
			vis[b[i].i]=1;
			ans+=b[i].val;
		}
	}
	if (b[i].val>0){
		for (;i<=tot&&b[i].val>0;i++){
			if (!vis[b[i].i]&&cnt[b[i].j]<n/2&&cnt[1]){
				cnt[b[i].j]++,cnt[1]--;
				vis[b[i].i]=1;
				ans+=b[i].val;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for (cin>>t;t;t--)solve();
	return 0;
}
