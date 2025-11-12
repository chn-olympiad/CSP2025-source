#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct node{
	int num,id;
}a[N][5];
int n,vis[5],t;
bool cmp(node a,node b){
	return a.num>b.num;
}
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n;
    	long long ans=0;
    	memset(vis,0,sizeof(vis));
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3;j++){
    			cin>>a[i][j].num;
    			a[i][j].id=j;
			}
		}
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+1+3,cmp);
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][1].num;
			vis[a[i][1].id]++;
		}
		int f=0;
		int c=n/2;
		if(vis[1]>c) f=1;
		if(vis[2]>c) f=2;
		if(vis[3]>c) f=3;
		if(!f){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i][1].id==f){
				q.push(a[i][1].num-a[i][2].num);
			}
		}
		for(int i=1;i<=vis[f]-c;i++){
			ans-=q.top();
			q.pop();
		}
		while(!q.empty()){
			q.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
