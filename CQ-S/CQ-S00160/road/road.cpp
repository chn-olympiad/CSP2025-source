#include<bits/stdc++.h>
using namespace std;
long long n,m,k,bian,cnt,ans,vlg[1010],fw[1010][1010],f[1010];
struct sss{
	long long start,to,qz;
};
bool operator >(sss a,sss b){
	return a.qz>b.qz;
}
priority_queue<sss,vector<sss>,greater<sss> > q;
long long find(long long x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void Union(long long a,long long b){
	long long a2=find(a),b2=find(b);
	if(a2!=b2) f[a2]=b2;
}
void kruskal(){
	while(bian<n-1){
		sss temp=q.top();
		q.pop();
		long long ct1=temp.start,ct2=temp.to,ww=temp.qz;
		if(find(ct1)!=find(ct2)){
			Union(ct1,ct2);
			ans+=ww;
//			cout<<ct1<<" "<<ct2<<endl;
			bian++;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (long long i=1;i<=n;i++) f[i]=i;
	for (long long i=1,u,v,w;i<=n;i++){
		cin>>u>>v>>w;
		q.push({u,v,w});
		q.push({v,u,w});
	}
	for(long long i=1;i<=k;i++){	//i个乡镇 
		cin>>vlg[i];	//改造费用 
		for (long long j=1;j<=n;j++){	//第i个乡镇与n个城市的道路连通费用 
			cin>>fw[i][j];
		}
	}
	for (long long i=1;i<=k;i++){	//中间乡镇 
		for (long long j=1;j<n;j++){	//第一个城市 
			for (long long l=j+1;l<=n;l++){	//第二个城市 
				q.push({j,l,fw[i][j]+fw[i][l]+vlg[i]});
				q.push({l,j,fw[i][j]+fw[i][l]+vlg[i]});
//				cout<<fw[i][j]+fw[i][l]+vlg[i]<<" ";
			}
		}
//		cout<<endl;
	}
	kruskal();
	cout<<ans;
	
	return 0;
}

