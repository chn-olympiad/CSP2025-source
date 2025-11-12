#include <bits/stdc++.h>
using namespace std;
long long x,y,z,d[10031],l[10031],qg[10031],sf[10031],hy[10031],ans;
vector<pair<int,long long>>b[10031];
set<pair<long long,int>>a;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","W",stdout);
	scanf("%lld%lld%lld",&x,&y,&z);
	for(int i=0;i<y;i++){
        long long u,m,l;
        scanf("%lld%lld%lld",&u,&m,&l);
        b[u].push_back({m,l});
        b[m].push_back({u,l});
	}
	for(int i=0;i<=10030;i++){
        l[i]=1e18;
        sf[i]=x+z+1;
        hy[i]=0;
        qg[i]=0;
        d[i]=0;
	}
	for(int i=1;i<=z;i++){
        long long o;
        scanf("%lld",&o);
        d[x+i]=o;
        for(int j=1;j<=x;j++){
            long long k;
            scanf("%lld",&k);
            b[x+i].push_back({j,k});
            b[j].push_back({x+i,k});
        }
	}
	a.insert({0,1});
	l[1]=0;
	while(a.size()>0){
        long long fir=a.begin()->first,sec=a.begin()->second;
        qg[sec]=1;
        a.erase(a.begin());
        for(int i=0;i<(int)b[sec].size();i++){
            long long yd=b[sec][i].first;
            if(qg[yd]==0 and l[yd]>b[sec][i].second+d[yd]){
                a.erase({l[yd],yd});
                sf[yd]=sec;
                l[yd]=b[sec][i].second+d[yd];
                a.insert({l[yd],yd});
            }
        }
	}
	for(int i=1;i<=x;i++){
        ans+=l[i];
        hy[sf[i]]=1;
	}
	for(int i=x+1;i<=x+z;i++){
        if(hy[i]>0){
            ans+=l[i];
        }
	}
    printf("%lld",ans);
	return 0;
}

