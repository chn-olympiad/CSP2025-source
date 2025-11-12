#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
const int N=2e5+7;
int T,n,m;
struct node{
	int p,cost;
}f[N];
int k[N],tot;
int q[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(q,0,sizeof q);
		tot=0;
		int ans=0;
		rep(i,1,n){
			int a,b,c;
			cin>>a>>b>>c;
			int mx=max(a,max(b,c));
			if(mx==a){
				f[i].p=1;
				q[1]++;
				ans+=a;
				f[i].cost=a-max(b,c);
			}
			else if(mx==b){
				f[i].p=2;
				q[2]++;
				ans+=b;
				f[i].cost=b-max(a,c);
			}
			else if(mx==c){
				f[i].p=3;
				q[3]++;
				ans+=c;
				f[i].cost=c-max(a,b);
			}
		}
		int pos=0;
		if(q[1]>n/2) pos=1;
		if(q[2]>n/2) pos=2;
		if(q[3]>n/2) pos=3;
		if(!pos){
			cout<<ans<<'\n';
			continue;
		}
		rep(i,1,n)
			if(f[i].p==pos) k[++tot]=f[i].cost;
		sort(k+1,k+1+tot);
		rep(i,1,q[pos]-n/2) ans-=k[i];
		cout<<ans<<'\n';
	}
	return 0;
}