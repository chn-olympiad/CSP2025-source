#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define ll long long
int n,m;
int ans;
int T;
int a[MAXN][5];
struct node{
	int x1,x2,num1,num2;
}b[MAXN];
int vis[5];
void solve(){
	scanf("%d",&n);
	ans=0;	
	priority_queue<int,vector<int>,greater<int> >q[4];
	for(int i=1;i<=3;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		b[i].x1=b[i].x2=-1;
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>=b[i].x1){
				b[i].x2=b[i].x1;
				b[i].num2=b[i].num1;
				b[i].x1=a[i][j];
				b[i].num1=j;
			}
			else if(a[i][j]>b[i].x2){
				b[i].x2=a[i][j];
				b[i].num2=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[b[i].num1]<n/2){
			vis[b[i].num1]++;
			q[b[i].num1].push(b[i].x1-b[i].x2);
			ans+=b[i].x1;
		}
		else{
			int u=q[b[i].num1].top();
			//cout<<i<<" "<<u<<endl;
			if(b[i].x1-b[i].x2>u){
				q[b[i].num1].pop();
				ans-=u;
				ans+=b[i].x1;
				q[b[i].num1].push(b[i].x1-b[i].x2);
			}
			else{
				ans+=b[i].x2;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
