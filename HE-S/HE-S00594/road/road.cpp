#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct node{
	long long to,next,w;
}line[4000005];
long long cnt,head[1000005];
void adl(long long u,long long v,long long w){
	line[++cnt].to=v;
	line[cnt].w=w;
	line[cnt].next=head[u];
	head[u]=cnt;
	return ;
}
long long ct[15][20005];
long long ctw[15];
long long visc[15];

long long dis[1000500];
long long vis[1000500];
struct pt{
	long long i,dis;
};
priority_queue<pt> q;
bool operator<(const pt &x,const pt &y){
	return x.dis>y.dis;
}
long long prim(long long ans){		//	cout<<"inans "<<ans<<endl;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	pt ppt;
	ppt.i=1;
	ppt.dis=0;
	dis[1]=0;
	q.push(ppt);
	
	while(!q.empty()){
		pt tp=q.top();
		q.pop();					//	cout<<ans<<" "<<tp.i<<" "<<tp.dis<<endl;
		if(vis[tp.i])continue;
		vis[tp.i]=1;
		ans+=dis[tp.i];
		
		if(tp.i>1000010){
			long long ti=tp.i-1000010;
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				if(dis[i]>ct[ti][i]){
					dis[i]=ct[ti][i];
					pt ppt;
					ppt.i=i;
					ppt.dis=dis[i];
					q.push(ppt);
				}
			}
		}
		else{
			for(int i=1;i<=k;i++){
				if(visc[i]==1&&vis[1000010+i]==0&&tp.i!=i+1000010){
					pt ppt;
					ppt.i=1000010+i;
					ppt.dis=ct[i][tp.i];
					dis[1000010+i]=min(dis[1000010+i],ct[i][tp.i]);		//cout<<"pushk  ct:"<<1000010+i<<" "<<tp.i<<"  "<<ct[i][tp.i]<<" "<<dis[1000010+i]<<endl;
					q.push(ppt);
				}
			}
			long long ti=tp.i;
			for(int i=head[ti];i;i=line[i].next){
				long long t=line[i].to;
				if(dis[t]>line[i].w){
					dis[t]=line[i].w;
					pt ppt;
					ppt.i=t;
					ppt.dis=dis[t];
					q.push(ppt);
				}	
			}
		}
		
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long tu,tv,tw;
		cin>>tu>>tv>>tw;
		adl(tu,tv,tw);
	}
	long long ys=0;
	for(int i=1;i<=k;i++){
		long long it=1;
		cin>>ctw[i];
		if(ctw[i]>0)it=0;
		for(int j=1;j<=n;j++){
			cin>>ct[i][j];
			if(ct[i][j]>0)it=0;
		}
		if(it==1){
			ys=1;
		}
	}
	if(ys==1){
		cout<<0<<endl;
		return 0;
	}
	long long mians=999999999999;
	for(int i=0;i<(1<<k);i++){
		long long wei=1,tp=i,iin=0;
		while(tp>0){
			if(tp%2==1){
				visc[wei]=1;
				iin+=ctw[wei];
			}
			wei++;
			tp/=2;
		}
		mians=min(mians,prim(iin));
		//cout<<prim(iin)<<endl;
		memset(visc,0,sizeof(visc));
		
	}
	
	cout<<mians<<endl;
	return 0;
} 
/*

	//ios::sync_with_stdio(0);
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/











