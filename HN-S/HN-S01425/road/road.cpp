#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=1e6+10;
long long n,m,k,up[2*N],ks[2*N],q,fd[2*N],ans,arc[2*N];
struct node{
	pair<long long,int long long> xy;
	long long z;
}e[2*M];
long long find(long long x){
	if(up[x]!=x){
		return up[x]=find(up[x]);
	}else{
		return x;
	}
}
bool cmp(node x1,node x2){
	if(x1.xy.first>n&&fd[x1.xy.first]==1){
		x1.z-=ks[(x1.xy.first)-n];
	}
	if(x2.xy.first>n&&fd[x2.xy.first]==1){
		x2.z-=ks[(x2.xy.first)-n];
	}
	return x1.z<x2.z;
}

void arcaea(){
	for(int i=1;i<=n+k;i++){
		up[i]=i;
	}
	for(int i=1;i<=k;i++){
		fd[i]>=1?fd[i]=1:fd[i]=0;
	}
	memset(arc,0,sizeof arc);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		long long x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		e[++q].xy.first=x;
		e[q].xy.second=y;
		e[q].z=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&ks[i]);
		long long ff=ks[i];
		for(int j=1;j<=n;j++){
			int z;
			scanf("%lld",&z);
			if(z>0){
				ff=1;
			}
			e[++q].xy.first=m+i;
			e[q].xy.second=j;
			e[q].z=z+ks[i];
		}
		if(ff==0){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=k+n;i++){
		up[i]=i;
	}
	sort(e+1,e+q+1,cmp);
//	for(int i=1;i<=q;i++){
//		cout<<e[i].xy.first<<" "<<e[i].xy.second<<' '<<e[i].z<<"\n";
//	}
//return 0;
	long long coni=n;
	for(int i=1;coni>0;i++){
		long long x=e[i].xy.first,y=e[i].xy.second,z=e[i].z;
		long long fx=find(x);int fy=find(y);//cout<<"arc";
		if(fx!=fy){
//			cout<<fx<<" "<<fy<<"\n";
			if(x<=n&&arc[x]==0){
				coni--;	
				arc[x]=1;
			}
			if(y<=n&&arc[y]==0){
				coni--;	
				arc[y]=1;
			}
			if(x>n){
				if(fd[x]==0){
					fd[x]=1;
					sort(e+1,e+q+1,cmp);
					i=0;coni=n;ans=0;
					arcaea();
					
				}else{
					if(fd[x]==1){
						fd[x]=2;
					}else{
						z-=ks[x-n];
					}
					ans+=z;
					up[fy]=fx;
//					cout<<i<<' '<<e[i].xy.first<<" "<<e[i].xy.second<<' '<<z<<"\n";
				}
			}else{
//				cout<<i<<' '<<e[i].xy.first<<" "<<e[i].xy.second<<' '<<z<<"\n";
				ans+=z;
				up[fy]=fx;
			}
		}
	}
	cout<<ans;
	return 0;
}
