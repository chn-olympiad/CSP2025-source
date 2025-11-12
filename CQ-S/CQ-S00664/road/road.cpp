#include<bits/stdc++.h>

using namespace std;
//long long!!!!!!!!!!!!!!!!!!!!
const int N=1e7+20;

pair<long long,pair<long long,long long> >p[N];
long long vl[20];
long long fa[N];
long long fin(long long u){
	if(fa[u]==u)return u;
	fa[u]=fin(fa[u]);
	return fa[u];
}
void merge(long long s1,long long s2){
	fa[fin(s1)]=fin(s2);
}

long long n,k,m,cnt=0;
void init(){
	for(long long i=1;i<=(n+k*2);i++)fa[i]=i;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	
	for(long long i=1;i<=m;i++){
		cnt++;
		scanf("%lld%lld%lld",&p[cnt].second.first,&p[cnt].second.second,&p[cnt].first);
	}
	bool all0=1;
	for(long long i=1;i<=k;i++){
		scanf("%lld",&vl[i]);
		if(vl[i]!=0)all0=0;
		for(long long j=1;j<=n;j++){
			cnt++;
			p[cnt].second.first=n+i;
			p[cnt].second.second=j;
			scanf("%lld",&p[cnt].first);
		}
	}
	sort(p+1,p+1+cnt);
		long long ans=0;
	if(all0){
		init();
		for(long long i=1;i<=cnt;i++){
			long long u=p[i].second.first,v=p[i].second.second;
//			if(u==0)cout<<i<<" "<<u<<" "<<v<<" "<<p[i].first<<"\n";
			
			if(fin(u)==fin(v))continue;
			merge(u,v);
			ans+=p[i].first;
		}
	}else{
		ans=LONG_LONG_MAX;
		for(long long S=0;S<(1<<k);S++){
			init();
			long long sum=0;
			bitset<20>s=S;
			for(long long i=1;i<=k;i++)if(s[i-1])sum+=vl[i];
//			cout<<s<<"\n";
//			cout<<sum<<"\n";
			for(long long i=1;i<=cnt;i++){
				long long u=p[i].second.first,v=p[i].second.second;
				if(u>n)if(!s[u-n-1])continue;
				if(v>n)if(!s[v-n-1])continue;
				if(fin(u)==fin(v))continue;
				merge(u,v);
				
				sum+=p[i].first;
//				cout<<"<"<<p[i].first<<" "<<u<<" "<<v<<">";
			}
//			cout<<sum<<"\n";
			ans=min(ans,sum);
		}
	}
	
	
	
	printf("%lld",ans);
	return 0;
}
/*
最小生成树

有n个点必定联通 
有k个点可以联通 ,且有c_i的点权 

 

*/
