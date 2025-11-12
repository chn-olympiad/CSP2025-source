#include<bits/stdc++.h>
using namespace std;
namespace xmx{
	const int N=1e5+5;
	const int M=1e6+5;
	int T;
	int n;
	int ans;
	struct node{
		int best,other,ca;
	};
	node a[N];
	int gs[N];
	int sta[N],tot,fir;
	inline void solve(){
		cin>>n;
		tot=fir=0;
		gs[1]=gs[2]=gs[3]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			int ax,by,cz;
			cin>>ax>>by>>cz;
			if(ax>=by && ax>=cz){
				a[i].best=1;
				if(by>=cz){
					a[i].other=2;
					a[i].ca=ax-by;
				}
				else{
					a[i].other=3;
					a[i].ca=ax-cz;
				}
			}
			else if(by>=ax && by>=cz){
				a[i].best=2;
				if(ax>=cz){
					a[i].other=1;
					a[i].ca=by-ax; 
				}
				else{
					a[i].other=3;
					a[i].ca=by-cz;
				}
			}
			else{
				a[i].best=3;
				if(ax>=by){
					a[i].other=1;
					a[i].ca=cz-ax;
				}
				else{
					a[i].other=2;
					a[i].ca=cz-by;
				}
			}
			gs[a[i].best]++;
			if(a[i].best==1)ans+=ax;
			if(a[i].best==2)ans+=by;
			if(a[i].best==3)ans+=cz;
		}
		if(gs[1]<=n/2 && gs[2]<=n/2 && gs[3]<=n/2){
			cout<<ans<<"\n";
			return;
		}
		else if(gs[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].best==1){
					sta[++tot]=a[i].ca;
				}
			}
			sort(sta+1,sta+tot+1);
			while(gs[1]>n/2){
				gs[1]--;
				ans-=sta[++fir];
			}
			cout<<ans<<"\n";
			return;
		}
		else if(gs[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].best==2){
					sta[++tot]=a[i].ca;
				}
			}
			sort(sta+1,sta+tot+1);
			while(gs[2]>n/2){
				gs[2]--;
				ans-=sta[++fir];
			}
			cout<<ans<<"\n";
			return;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i].best==3){
					sta[++tot]=a[i].ca;
				}
			}
			sort(sta+1,sta+tot+1);
			while(gs[3]>n/2){
				gs[3]--;
				ans-=sta[++fir];
			}
			cout<<ans<<"\n";
			return;
		}
		return;
	}
	signed main(){
		cin>>T;
		while(T--)solve();
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return xmx::main();
}
