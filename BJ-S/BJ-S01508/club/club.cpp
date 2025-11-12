#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node1{
	ll x,id;
}a[N][3];
struct node2{
	ll id,x;
};
bool operator <(node2 n1,node2 n2){
	return n1.x>n2.x;
}
bool cmp(node1 n1,node1 n2){
	return n1.x>n2.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		bool f=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].x;
				a[i][j].id=j;
			}
			if(a[i][2].x!=0||a[i][3].x!=0) f=1;
		}
		if(f==0){
			ll ans=0;
			ll b[N];
			int tot=0;
			for(int i=1;i<=n;i++){
				b[++tot]=a[i][1].x;
			}
			sort(b+1,b+tot+1,greater<int>());
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			cout<<ans<<endl;
		}else {
			for(int i=1;i<=n;i++){
				sort(a[i]+1,a[i]+4,cmp);
			}
			if(n==2){
				if(a[1][1].x>a[2][1].x){
					cout<<a[1][1].x+a[2][2].x;
				}else{
					cout<<a[1][2].x+a[2][1].x;
				}
				return 0;
			}
			priority_queue<node2> q[4];
			for(int i=1;i<=n;i++){
				node1 y=a[i][1],z=a[i][2],k=a[i][3];
				if(q[y.id].size()+1<=n/2){
					q[y.id].push({i,y.x});
				}else{
					node2 cur=q[y.id].top();
					q[y.id].pop();
					if(q[a[cur.id][2].id].size()+1<=n/2){
						ll s1=a[cur.id][2].x+y.x;
						ll s2=cur.x+z.x;
						if(s1>s2){
							q[a[cur.id][2].id].push({cur.id,a[cur.id][2].x});
							q[y.id].push({i,y.x});
						}else{
							q[y.id].push(cur);
							q[z.id].push({i,z.x});
						}
					}else{
						ll s1=a[cur.id][3].x+y.x;
						ll s2=cur.x+k.x;
						if(s1>s2){
							q[a[cur.id][3].id].push({cur.id,a[cur.id][3].x});
							q[y.id].push({i,y.x});
						}else {
							q[y.id].push(cur);
							q[k.id].push({i,k.x});
						}
					}
				}
			}
			ll ans=0;
			while(q[1].size()){
				node2 cur=q[1].top();
				q[1].pop();
				ans+=cur.x;
			}
			while(q[2].size()){
				node2 cur=q[2].top();
				q[2].pop();
				ans+=cur.x;
			}
			while(q[3].size()){
				node2 cur=q[3].top();
				q[3].pop();
				ans+=cur.x;
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
