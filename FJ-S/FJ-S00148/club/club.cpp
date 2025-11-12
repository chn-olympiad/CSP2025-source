#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct _ns{
	int js[3];
	int ai,bi,ci;
}ns[200005];
int abcs[3];
int s;
bool cmp(_ns u,_ns v){
	return u.js[u.bi]<v.js[v.bi];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		s=0;
		abcs[0]=abcs[1]=abcs[2]=0;
		scanf("%d",&n);
		for(signed i=1;i<=n;i++){
			scanf("%d%d%d",&ns[i].js[0],&ns[i].js[1],&ns[i].js[2]);
			if(ns[i].js[0]>ns[i].js[1]){
				if(ns[i].js[0]>ns[i].js[2]){
					ns[i].ai=0;
					if(ns[i].js[1]>ns[i].js[2]){
						ns[i].bi=1;
					}else{
						ns[i].bi=2;
					}
				}else{
					ns[i].ai=2;
					ns[i].bi=0;
				}
			}else{
				if(ns[i].js[1]>ns[i].js[2]){
					ns[i].ai=1;
					if(ns[i].js[0]>ns[i].js[2]){
						ns[i].bi=0;
					}else{
						ns[i].bi=2;
					}
				}else{
					ns[i].ai=2;
					ns[i].bi=1;
				}
			}
			s+=ns[i].js[ns[i].ai];
			ns[i].js[ns[i].bi]-=ns[i].js[ns[i].ai];
		}
		sort(ns+1,ns+1+n,cmp);
		for(int i=1,n2=n/2;i<=n;i++){
			if(abcs[ns[i].ai]==n2){
				s+=ns[i].js[ns[i].bi];
			}else abcs[ns[i].ai]++;
		}
		printf("%d\n",s);
	}
	return 0;
}
