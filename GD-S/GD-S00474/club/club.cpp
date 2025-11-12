#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N][4];
struct node{
	int u;
	long long w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
}k,kk;
priority_queue<node> q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while(T--){
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		int n; cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long maxx=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxx==a[i][1]){
				long long maxn=max(a[i][2],a[i][3]);
				k.u=i; k.w=a[i][1]-maxn; q1.push(k);
				ans+=a[i][1];
				if(q1.size()>n/2){
					k=q1.top(); q1.pop();
					int u=k.u; long long w=k.w; ans-=w;
					if(maxn==a[i][2]){
						kk.u=i; kk.w=a[i][2]-a[i][3]; q2.push(kk);
					}
					else{
						kk.u=i; kk.w=a[i][3]-a[i][2]; q3.push(kk);
					}
				}
			}
			else if(maxx==a[i][2]){
				long long maxn=max(a[i][1],a[i][3]);
				k.u=i; k.w=a[i][2]-maxn; q2.push(k);
				ans+=a[i][2];
				if(q2.size()>n/2){
					k=q2.top(); q2.pop();
					int u=k.u; long long w=k.w; ans-=w;
					if(maxn==a[i][1]){
						kk.u=i; kk.w=a[i][1]-a[i][3]; q1.push(kk);
					}
					else{
						kk.u=i; kk.w=a[i][3]-a[i][1]; q3.push(kk);
					}
				}
			}
			else{
				long long maxn=max(a[i][2],a[i][1]);
				k.u=i; k.w=a[i][3]-maxn; q3.push(k);
				ans+=a[i][3];
				if(q3.size()>n/2){
					k=q3.top(); q3.pop();
					int u=k.u; long long w=k.w; ans-=w;
					if(maxn==a[i][2]){
						kk.u=i; kk.w=a[i][2]-a[i][1]; q2.push(kk);
					}
					else{
						kk.u=i; kk.w=a[i][1]-a[i][2]; q1.push(kk);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
