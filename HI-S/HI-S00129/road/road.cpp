#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=1e6;
int n,m,k,u[M+5],v[M+5],w[M+5];
bool insr[N+5]; int pian[N+5]; long long ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=N;i++){
		pian[i]=int(1e9)+5;
	}for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		pian[i]=min(pian[i],w[i]);
	}for(int i=1;i<=k;i++){
		int c,p;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&p);
			if (p==0){
				insr[j]=true;
			}
		}
	}for(int i=1;i<=n;i++){
		if (insr[i]==false) ans+=pian[i];
	}printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

