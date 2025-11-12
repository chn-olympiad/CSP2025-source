#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],s[10005],minx,minxt,minxw,a,cnt=0;
long long sum=0,c[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		if(i==1){
			minx=w[1];
			minxt=u[1];
			minxw=v[1];
		}else{
			minx=min(minx,w[i]);
			minxt=u[i];
			minxw=v[i];
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;i++){
			scanf("%d",&a);
		}
	}
	if(k<=0){
		s[minxt]=1,s[minxw]=1;
		sum+=minx;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				continue;
			}
			cnt=0;
			for(int j=1;j<=m;j++){
				if(u[j]==i||v[j]==i){
					if(cnt==0){
						minx=w[j];
						minxt=u[j];
						minxw=v[j];
						cnt=1;
					}else{
						minx=min(minx,w[j]);
						minxt=u[j];
						minxw=v[j];
					}
				}
			}
			sum+=minx;
			s[minxt]=1;
			s[minxw]=1;
		}
		printf("%lld",sum);
	}else{
		sort(c+1,c+k+1);
		printf("%lld",c[1]);
	}
	return 0;
}
