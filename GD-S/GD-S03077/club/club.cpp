#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int s2,p;
};
struct D{
	int x,p;
}k[N][3];
bool operator<(node a,node b){return a.s2>b.s2;}
priority_queue<node>q[3];
bool cmp(D a,D b){
	return a.x>b.x;
}
void solve(){
	int n;cin>>n;
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=0,x;j<3;j++)cin>>x,k[i][j]={x,j};
		sort(k[i],k[i]+3,cmp);
		int p=k[i][0].p;
		q[p].push({k[i][0].x-k[i][1].x,i});
		s+=k[i][0].x;
		if(q[p].size()>n/2){
			node dt=q[p].top();s-=dt.s2;q[p].pop();
			q[k[dt.p][1].p].push({k[dt.p][1].x-k[dt.p][1].x,dt.p});
		}
	}cout<<s<<endl;
	for(int i=0;i<3;i++)
	while(q[i].size())q[i].pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
} 
