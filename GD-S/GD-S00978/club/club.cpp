#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=5e5+10;
int n,cnt,te[5];
struct node{
	int t[4],c,m1,m2;
}a[N];
bool cmp(node x,node y){
	return x.c>y.c;
}
bool vis[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--){
		memset(te,0,sizeof te);
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i].t[1]);
			scanf("%lld",&a[i].t[2]);
			scanf("%lld",&a[i].t[3]);
//			cin>>a[i].t[1]>>a[i].t[2]>>a[i].t[3];
			int p=max(a[i].t[1],max(a[i].t[2],a[i].t[3]));
			if(p==a[i].t[2]){
				a[i].m1=2;
				if(a[i].t[1]>a[i].t[3]){
					a[i].m2=1;
				}else{
					a[i].m2=3;
				}
			}
			if(p==a[i].t[3]){
				a[i].m1=3;
				if(a[i].t[2]>a[i].t[1]){
					a[i].m2=2;
				}else{
					a[i].m2=1;
				}
			}
			if(p==a[i].t[1]){
				a[i].m1=1;
				if(a[i].t[2]>a[i].t[3]){
					a[i].m2=2;
				}else{
					a[i].m2=3;
				}
			}
			a[i].c=a[i].t[a[i].m1]-a[i].t[a[i].m2];
			
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(te[a[i].m1]>=n/2){
				te[a[i].m2]++;
				ans+=a[i].t[a[i].m2];
			}else{
				te[a[i].m1]++;
				ans+=a[i].t[a[i].m1];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
