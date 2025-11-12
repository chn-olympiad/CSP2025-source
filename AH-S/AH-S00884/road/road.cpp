#include<bits/stdc++.h>
using namespace std;
long long n,m,k,q,kk,u1,wmin=1000003;
long long u[10002],v[10002],mon[1000003],v1,w[1000003],t[100002];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		scanf("%lld",&u[i]);
		scanf("%lld",&v[i]);
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=k*(n+1);i++){
			scanf("%lld",&t[i]);
	}
	memset(mon,1000003,wmin-3);
	for(long long i=1;i<=n-1;i++){
		for(long long j=1;j<=m;j++){
			wmin=min(wmin,w[j]);
			if(w[j]==wmin){
				v1=v[j];
				u1=u[j];
			}
		}
		kk=0;
		for(long long j=1;j<=m;j++){
			if(v1==u[j] or (v1==v[j] && u1!=u[j])){
				mon[kk]=w[j];
				kk++;
			}
			else{
				if(u1==v[j] or (u1==u[j] && v1!=v[j])){
					mon[kk]=w[j];
					kk++;
				}
			}
		}
		sort(mon,mon+kk);
		q=q+mon[0];
		for(long long j=1;j<=m;j++){
			if(mon[0]==w[j]){
				w[j]=1000003;
			}
		}
		memset(mon,1000003,kk);
	}
	printf("%.lld",q);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
