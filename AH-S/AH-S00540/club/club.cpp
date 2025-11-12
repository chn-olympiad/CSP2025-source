#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int a[100005][4];
struct node{int c,id;}a1[100005][4];
int ans=0;
void dfs(int start,int x1,int x2,int x3,int sum){
	if(start==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x1+1<=n/2)dfs(start+1,x1+1,x2,x3,sum+a[start][1]);
	if(x2+1<=n/2)dfs(start+1,x1,x2+1,x3,sum+a[start][2]);
	if(x3+1<=n/2)dfs(start+1,x1,x2,x3+1,sum+a[start][3]);
}
bool cmp(node a,node b){
	return a.c>b.c;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	priority_queue<int,vector<int>,greater<int> > que[4];
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a1[i][1].c=a[i][1],a1[i][2].c=a[i][2],a1[i][3].c=a[i][3];
			a1[i][1].id=1,a1[i][2].id=2,a1[i][3].id=3;
			sort(a1[i]+1,a1[i]+4,cmp);
		}
		if(n<=10){
			dfs(1,0,0,0,0);	
			cout<<ans<<endl;
		}
		else{
			int ans2=0;
			for(int i=0;i<=3;i++){
				while(!que[i].empty()){
					que[i].pop();
				}
			}	
			for(int i=1;i<=n;i++){
				if((int)que[a1[i][1].id].size()<n/2){
					ans2+=a1[i][1].c;
					que[a1[i][1].id].push(a1[i][1].c-a1[i][2].c);
				}
				else if(que[a1[i][1].id].top()<=a1[i][1].c-a1[i][2].c){
					ans2+=a1[i][1].c-que[a1[i][1].id].top();
					que[a1[i][1].id].pop();
					que[a1[i][1].id].push(a1[i][1].c-a1[i][2].c);
				}				
				else{
					ans2+=a1[i][2].c;
					que[a1[i][2].id].push(1e9);
				}
			}	
			cout<<ans2<<endl;				
		}
	}
		
	return 0;
}
