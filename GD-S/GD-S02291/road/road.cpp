#include<bits/stdc++.h>
#define pp pair<int,pair<int,int> >
using namespace std;
const int N=1e4,Z=10;
int n,m,k,xc[Z+1][N+1],xcj[Z+1],fa[N+1],cnt=0;
priority_queue<pp,vector<pp>,greater<pp> >q[Z+1],q1; 
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		pp a;
		cin>>a.second.first>>a.second.second>>a.first;
		q1.push(a);
	}
	if(k==0){
		long long ans=0; 
		while(cnt<n-1){
			int zx=find(q1.top().second.first);
			int zy=find(q1.top().second.second);
			int zhi=q1.top().first;
			if(zx!=zy){
				fa[zy]=zx;
				ans+=zhi;
				cnt++;
			}
			q1.pop();
		}
		cout<<ans;
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=k;i++){
		cin>>xcj[i];
		for(int j=1;j<=n;j++){
			cin>>xc[i][j];
		}
	}
	for(int ii=0;ii<k;ii++){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				q[ii+1].push(make_pair(xc[ii+1][i]+xc[ii+1][j],make_pair(i,j)));
			}
		}
	}
//	for(int i=1;i<=k;i++){
//		while(!q[i].empty()){
//			cout<<q[i].top().first<<' '<<q[i].top().second.first<<' '<<q[i].top().second.second<<endl;
//			q[i].pop();
//		}
//	}
	while(cnt<n-1){
//		cout<<cnt<<' ';
		int f=0;
		pp a;
		int zx=find(q1.top().second.first);
		int zy=find(q1.top().second.second);
		if(zx!=zy)a=q1.top();
		else q1.pop();
		for(int i=1;i<=k;i++){
			int zx1=find(q[i].top().second.first);
			int zy1=find(q[i].top().second.second);
			if(zx1!=zy1&&q[i].top().first<a.first){
				zx=zx1;
				zy=zy1;
				f=i;
			}
			else if(zx1==zy1){
				q[i].pop();
			}
		}
		if(f){
			fa[zy]=zx;
			ans+=q[f].top().first;
			cnt++;
			q[f].pop();
		}
		else if(zx!=zy){
			fa[zy]=zx;
			ans+=a.first;
			cnt++;
			q1.pop();
		}
	}
	cout<<ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
