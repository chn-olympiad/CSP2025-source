#include<bits/stdc++.h>
using namespace std;
struct dian{
	int a,b,c;
	const bool operator<(dian&l){
		return c<l.c;
	}
	const void operator=(const dian l){
		a=l.a;b=l.b;c=l.c;
	}
}jh[1200300];
struct pr{
	int a,b;
};
int n,bj[10200],nc[15][10200],pl[15]={0,1,2,3,4,5,6,7,8,9,10,11};
vector<pr>lj[10200];
inline const int find(int a){
	return bj[a]==0||bj[a]==a?a:bj[a]=find(bj[a]);
}
int main(){
	int a,b,c,m,t,a1,b1,c1;
	long long sum=0,sum1=0,sum2=10000000000000000LL;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	a=b=c=a1=b1=c1=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&jh[i].a,&jh[i].b,&jh[i].c);
	}
	for(int i=1;i<=t;i++){
		scanf("%d",&nc[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&nc[i][j]);
		}
	}
	for(int t1=0;t1<=t;t1++){
		sort(jh+1,jh+1+m);
		sum=0;
		
		memset(bj,0,sizeof(bj));
		for(int i=1;i<=m;i++){
			if(sum>=n+t1-1)break;
			a1=find(jh[i].a);
			b1=find(jh[i].b);
			//lj[a].push_back({b,jh[i].c});
			//lj[b].push_back({a,jh[i].c});
			if(a1!=b1){
				sum++;
				sum1+=jh[i].c;
				bj[a1]=b1;
			}
		}
		sum2=min(sum2,sum1);
		if(t1!=t){
			sum1=0;
			for(int j=1;j<=n;j++){
				m++;
				jh[m]=(dian){t1+10001,j,nc[t1+1][j]};
			}
			for(int j=1;j<=t1+1;j++)sum1+=nc[j][0];
		}
	}
	
	printf("%lld",sum2);
	return 0;
} 
