#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
struct Node{
	ll ind,val;
}a[100005][5];
bool cmp(Node x,Node y){
	return x.val>y.val;
}
struct qN{
	ll i,j;
	bool operator <(const qN& y)const{
		return a[i][j].val-a[i][j+1].val>a[y.i][y.j].val-a[y.i][y.j+1].val;
	}  
};
priority_queue<qN>q[4];
ll T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		for(int j=1;j<=3;j++)while(!q[j].empty())q[j].pop();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].val;
				a[i][j].ind=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			q[a[i][1].ind].push({i,1});
			ans+=1ll*a[i][1].val;
			while(q[a[i][1].ind].size()>n/2){
				qN tmp=q[a[i][1].ind].top();
				q[a[i][1].ind].pop();
				ans-=a[tmp.i][tmp.j].val-a[tmp.i][tmp.j+1].val;
				q[a[tmp.i][tmp.j+1].ind].push({tmp.i,tmp.j+1});
			}
		}
		cout<<ans<<"\n";	
	}
	return 0;
} 
