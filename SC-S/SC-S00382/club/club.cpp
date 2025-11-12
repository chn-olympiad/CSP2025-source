#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,a[4];
struct node{int w,cha1,cha2;}b[N];
bool cmp(node a,node b){return a.cha1>b.cha1;}
void solve(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[j];
		ans+=a[1];
		if(a[2]>a[3])b[i].w=0;
		else b[i].w=1;
		b[i].cha1=max(a[2],a[3])-a[1];
		b[i].cha2=min(a[2],a[3])-max(a[2],a[3]);
	}
	sort(b+1,b+n+1,cmp);
	int i=1;
	priority_queue<int> pq[2];
	for(;i<=n/2;i++){
		ans+=b[i].cha1;
		pq[b[i].w].push(b[i].cha2);
	}
	for(;b[i].cha1>0;i++){
		if(pq[b[i].w].size()==n/2){
			int k=pq[b[i].w].top();
			if(b[i].cha1+k>0){
				pq[b[i].w].pop();
				pq[b[i].w].push(b[i].cha2);
				ans+=b[i].cha1+k;
				pq[(b[i].w+1)%2].push(-k);
			}
		}else{
			ans+=b[i].cha1;
			pq[b[i].w].push(b[i].cha2);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}