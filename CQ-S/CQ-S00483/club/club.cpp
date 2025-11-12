#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
int t,n;
const int N=1e5+10;
int a[N][5];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	int x=0,y=0,z=0;
	multiset<int> s[4];
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=max({a[i][1],a[i][2],a[i][3]});
		int r=(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]?1:a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]?2:3);
		int k=(r==1?2:r==2?3:1);
		int t=6-r-k;
		s[r].insert(min(a[i][r]-a[i][t],a[i][r]-a[i][k]));
		if(r==1) x++;
		if(r==2) y++;
		if(r==3) z++;
		if((r==1&&x>n/2)||(r==2&&y>n/2)||(r==3&&z>n/2)) ans-=*s[r].begin(),s[r].erase(s[r].begin());
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve(); 
	return 0;
}

