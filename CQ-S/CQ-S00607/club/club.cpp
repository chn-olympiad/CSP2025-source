#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T=1,n,m,mx,ans,a[N][3],b[N][3],w[N];
struct node{
	int id,x;
	bool operator<(const node&y)const{
		if(a[x][id]-b[x][1]==a[y.x][y.id]-b[y.x][1])return a[x][id]>a[y.x][y.id];
		return a[x][id]-b[x][1]>a[y.x][y.id]-b[y.x][1];
	}
};
priority_queue<node>q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			w[i]=max({a[i][0],a[i][1],a[i][2]});
			for(int j=0;j<3;j++)b[i][j]=a[i][j];
			sort(b[i],b[i]+3);
			if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]){ans+=w[i];continue;}
			if(a[i][0]==a[i][1]&&a[i][0]==w[i]){ans+=w[i];continue;}
			if(a[i][0]==a[i][2]&&a[i][0]==w[i]){ans+=w[i];continue;}
			if(a[i][2]==a[i][1]&&a[i][1]==w[i]){ans+=w[i];continue;}
			for(int j=0;j<3;j++)if(w[i]==a[i][j])q[j].push({j,i});
		}
		for(int i=0;i<3;i++)if(q[i].size()>q[mx].size())mx=i;
		while(q[mx].size()>n>>1){
			node u=q[mx].top();q[mx].pop();
			for(int i=0;i<3;i++)if(i!=mx)u.id=i;
			for(int i=0;i<3;i++)if(i!=mx)if(a[u.x][u.id]<a[u.x][i])u.id=i;
			q[u.id].push(u);
		}
		for(int i=0;i<3;i++)while(q[i].size())ans+=a[q[i].top().x][i],q[i].pop();
		cout<<ans<<'\n';
	}
	return 0;
}
/*
愿美德支撑信者魂灵
愿礼法惩戒罪人言行
愿圣琴的音乐永不停息
愿高塔永远为她而矗立 
*/
