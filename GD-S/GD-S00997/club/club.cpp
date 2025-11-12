#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,ans,cnt[3],MX;
priority_queue<int,vector<int>,greater<int>> q;
struct nd{
	int v[3],id;
}a[maxn];
void solve(){
	while(!q.empty()) q.pop();
	ans=cnt[0]=cnt[1]=cnt[2]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].v[0],&a[i].v[1],&a[i].v[2]);
		int mx=max({a[i].v[0],a[i].v[1],a[i].v[2]});
		ans+=mx;
		if(a[i].v[0]==mx) cnt[0]++,a[i].id=0;
		else if(a[i].v[1]==mx) cnt[1]++,a[i].id=1;
		else cnt[2]++,a[i].id=2;
	}
	int tmp=max({cnt[0],cnt[1],cnt[2]});
	if(cnt[0]==tmp) MX=0;
	else if(cnt[1]==tmp) MX=1;
	else MX=2;
	for(int i=1;i<=n;i++){
		if(a[i].id==MX){
			int tmp=0;
			for(int j=0;j<=2;j++) if(j!=MX) tmp=max(tmp,a[i].v[j]);
			q.push(a[i].v[MX]-tmp);
		}
	}
	for(int i=1;i<=cnt[MX]-n/2;i++){
		ans-=q.top();
		q.pop();
	}
	// // cout<<ans<<"\n";
	// for(int i=1;i<=cnt[MX]-n/2;i++){
		// ans-=a[i].v[MX];
		// int tmp=0;
		// for(int j=0;j<=2;j++) if(j!=MX) tmp=max(tmp,a[i].v[j]);
		// ans+=tmp;
	// }
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
}
