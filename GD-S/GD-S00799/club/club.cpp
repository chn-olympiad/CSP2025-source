#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mk(x,y) make_pair(x,y)
const int M=1e5+10;
int T,n;
struct NODE{
	int a,b,c;
}nd[M];
bool cmp(const pii&a,const pii&b){
	return a.second>b.second;
}
pii ls[M];
int tot[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		int res=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&nd[i].a,&nd[i].b,&nd[i].c);
			res+=nd[i].a;
			if(nd[i].b<nd[i].c)ls[i]=mk(2,nd[i].c-nd[i].a);
			else ls[i]=mk(1,nd[i].b-nd[i].a);
		}
		sort(ls+1,ls+n+1,cmp);
		memset(tot,0,sizeof tot);
		for(int i=1;i<=n/2;i++)res+=ls[i].second,tot[ls[i].first]++;
		for(int i=n/2+1;i<=n;i++){
			if(ls[i].second>0){
				res+=ls[i].second,tot[ls[i].first]++;
			}
		}
		if(max(tot[1],tot[2])>=n/2){
			if(tot[1]>=n/2){
				res=0;
				for(int i=1;i<=n;i++){
					res+=nd[i].b;
					if(nd[i].a<nd[i].c)ls[i]=mk(2,nd[i].c-nd[i].b);
					else ls[i]=mk(0,nd[i].a-nd[i].b);
				}
				sort(ls+1,ls+n+1,cmp);
				for(int i=1;i<=n/2;i++)res+=ls[i].second;
			}else{
				res=0;
				for(int i=1;i<=n;i++){
					res+=nd[i].c;
					if(nd[i].a<nd[i].b)ls[i]=mk(1,nd[i].b-nd[i].c);
					else ls[i]=mk(0,nd[i].a-nd[i].c);
				}
				sort(ls+1,ls+n+1,cmp);
				for(int i=1;i<=n/2;i++)res+=ls[i].second;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
