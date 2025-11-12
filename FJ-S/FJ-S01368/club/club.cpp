#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
bool fl[N];
struct node{
	int m1,m2,m3,sum,maxx;
}a[N];
vector<node> aa,b,c;
bool cmp(node x,node y){
	return x.sum<y.sum;
}
int	main( ){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n,c1=0,c2=0,c3=0,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].m1,&a[i].m2,&a[i].m3);
			a[i].sum=a[i].m1+a[i].m2+a[i].m3;
			a[i].maxx=max(a[i].m1,max(a[i].m2,a[i].m3));
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			ans+=a[i].maxx;
			if(a[i].m1==a[i].maxx){
				aa.push_back(a[i]);
			}else if(a[i].m2==a[i].maxx){
				b.push_back(a[i]);
			}else{
				c.push_back(a[i]);
			}
		}
//		int i=aa.size(),j=b.size(),k=c.size();
//		while(aa.size()>n/2){
//			
//		}
		printf("%d\n",ans);
	}
	return 0;
}
