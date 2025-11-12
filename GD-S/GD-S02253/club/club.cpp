#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,vis[N],s[4],p1,p2,b[N][3];
struct edge{
	int val,x,y;
}a[N*4];
bool cmp(edge u,edge v){
	return u.val>v.val;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		memset(s,0,sizeof s);
		int cnt=0,ans=0;
		p1=p2=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
//				cin >> a[i][j];
				cnt++;
				cin >> a[cnt].val;
				b[j][i]=a[cnt].val;
				a[cnt].x=i;
				a[cnt].y=j;
				if (j==2) p1+=a[cnt].val;
				if (j==3) p1+=a[cnt].val,p2+=a[cnt].val;
			}
		}
		if (p1==0){
			sort(b[1]+1,b[1]+n+1);
			for (int i=n;i>=n/2+1;i--){
				ans+=b[1][i];
			}
			cout << ans << '\n';
			continue;
		}
//		if (p2==0){
//			
//		}
		sort(a+1,a+cnt+1,cmp);
		for (int i=1;i<=cnt;i++){
			if (vis[a[i].x]) continue;
			if (s[a[i].y]==n/2) continue;
			vis[a[i].x]=1;
			s[a[i].y]++;
			ans+=a[i].val;
		}
		cout << ans << '\n';
	}
}
