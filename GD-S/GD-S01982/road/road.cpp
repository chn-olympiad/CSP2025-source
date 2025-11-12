#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,a,t;
map<pair<int,int>,int>mp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		mp[make_pair(u,v)]=w;
		mp[make_pair(v,u)]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&a);
			if(!a)t++;
		}
	}
	if(!k){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)
				mp[make_pair(j,k)]=max(mp[make_pair(j,k)],mp[make_pair(i,k)]+mp[make_pair(j,i)]);
			}
		}
		printf("%lld",mp[make_pair(1,n)]);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(t==k*(n+1)){
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
			mp[make_pair(j,k)]=max(mp[make_pair(j,k)],mp[make_pair(i,k)]+mp[make_pair(j,i)]);
		}
	}
	printf("%lld",mp[make_pair(1,n)]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
