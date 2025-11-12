#include<bits/stdc++.h>
using namespace std;
int Tim=1;
const int N=1e5+5;
int n;
struct node{
	int a[4];
}a[N];
int ans;
int vis[N];
int tot1,tot2,tot3;
int d[N],cnt,nd;
void Solve(){
	cin>>n;
	ans=0;
	tot1=tot2=tot3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3]; 
		if(a[i].a[1]>=a[i].a[2]&&a[i].a[1]>=a[i].a[3]){
			ans+=a[i].a[1];
			vis[i]=1;
			tot1++;
			continue;
		}
		if(a[i].a[2]>=a[i].a[1]&&a[i].a[2]>=a[i].a[3]){
			ans+=a[i].a[2];
			vis[i]=2;
			tot2++;
			continue;
		}
		ans+=a[i].a[3];
		vis[i]=3;
		tot3++;
	}
	if(tot1<=n/2&&tot2<=n/2&&tot3<=n/2){
		cout<<ans<<'\n';
		return;
	}
//	cerr<<tot1<<' '<<tot2<<' '<<tot3<<'\n';
	cnt=0;
	if(tot1>n/2){
		nd=tot1-n/2;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				d[++cnt]=a[i].a[1]-max(a[i].a[2],a[i].a[3]);
			}
		}
	}
	if(tot2>n/2){
		nd=tot2-n/2;
		for(int i=1;i<=n;i++){
			if(vis[i]==2){
				d[++cnt]=a[i].a[2]-max(a[i].a[1],a[i].a[3]);
			}
		}
	}
	if(tot3>n/2){
		nd=tot3-n/2;
		for(int i=1;i<=n;i++){
			if(vis[i]==3){
				d[++cnt]=a[i].a[3]-max(a[i].a[1],a[i].a[2]);
			}
		}
	}
	sort(d+1,d+cnt+1);
	for(int i=1;i<=nd;i++){
		ans-=d[i];
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>Tim;
	while(Tim--){
		Solve();
	}	
	return 0;
}
