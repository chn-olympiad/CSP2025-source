#include<bits/stdc++.h>
using namespace std;int n,m,k,x,y,z,i,j,a[11],b[10020],c[10020];long long s;
vector<array<int,2>>q[10020];priority_queue<array<int,2>>p;
main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	while(m--)scanf("%d%d%d",&x,&y,&z),q[x].push_back({y,z}),q[y].push_back({x,z});
	for(i=1;i<=k;i++){
		scanf("%d",&a[i]);for(j=1;j<=n;j++)
			scanf("%d",&z),q[i+n].push_back({j,z}),q[j].push_back({i+n,z});
	}for(j=1;j<=n+k;j++)b[j]=1e9+10;b[1]=0;p.push({0,1});
	while(p.size()){
		auto w=p.top();p.pop();if(c[w[1]])continue;c[w[1]]=1;
		s+=b[w[1]];
		for(auto i:q[w[1]]){
			if(i[0]>n){
				if(b[i[0]]>i[1]+a[i[0]-n])p.push({-(b[i[0]]=i[1]+a[i[0]-n]),i[0]});
			}else if(b[i[0]]>i[1])p.push({-(b[i[0]]=i[1]),i[0]});
		}
	}printf("%lld",s);
}/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
