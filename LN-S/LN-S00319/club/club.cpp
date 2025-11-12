#include <bits/stdc++.h>
using namespace std;
int t,n,a[100040],b[100040],c[100040],d[100040];
int al[100040],bl[100040],cl[100040];
//int jl[100040],jk[100040];
//int jx[100040];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof a);
		memset(al,0,sizeof al);
		memset(b,0,sizeof b);
		memset(bl,0,sizeof bl);
		memset(c,0,sizeof c);
		memset(cl,0,sizeof cl);
		int ans=0;
		int an=0,bn=0,cn=0;
		bool qq=true;
		//memset(f,0,sizeof f);
		scanf("%d",&n);
		int bg=n/2;
		int da=1,db=1,dc=1;
		for (int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			if (b[i]||c[i]) qq=false;
			if (a[i]>=b[i]&&a[i]>=c[i]){
				an++;
				d[i]=a[i];
				//al[i]=1;
				int v=max(b[i],c[i]);
				al[da++]=a[i]-v;
				//if (b[i]>=c[i]){
					//bl[i]=2,cl[i]=3;
					//al[i]=abs(a[i]-b[i]);
					//jk[i]=abs(b[i]-c[i]);
				//}
				//else{
					//bl[i]=3,cl[i]=2;
				//	al[i]=abs(a[i]-c[i]);
					//jk[i]=abs(b[i]-c[i]);
				//}
			}
			else if (b[i]>=a[i]&&b[i]>=c[i]){
				bn++;
				//bl[i]=1;
				d[i]=b[i];
				int v=max(a[i],c[i]);
				bl[db++]=b[i]-v;
				//if (a[i]>=c[i]){
					//al[i]=2,cl[i]=3;
				//	bl[i]=abs(a[i]-b[i]);
				//}
				//else{
					//al[i]=3,cl[i]=2;
				//	bl[i]=abs(b[i]-c[i]);
				//}
			}
			else if (c[i]>=a[i]&&c[i]>=b[i]){
				cn++;
				//cl[i]=1;
				d[i]=c[i];
				int v=max(b[i],a[i]);
				cl[dc++]=c[i]-v;
				//if (a[i]>=b[i]){
					//al[i]=2,bl[i]=3;
				//	cl[i]=abs(a[i]-c[i]);
				//}
				//else{
					//al[i]=3,bl[i]=2;
				//	cl[i]=abs(b[i]-c[i]);
				//}
				
				//jk[i]=abs(b[i]-a[i]);
			}
			//jl[i]=abs(a[i]-b[i]);
			//jk[i]=abs(b[i]-c[i]);
			//jx[i]=abs(a[i]-c[i]);
		}
		sort(al+1,al+da+1);
		sort(bl+1,bl+db+1);
		sort(cl+1,cl+dc+1);
		//sort(jk+1,jk+n+1);
		if (qq){
			sort(a+1,a+n+1);
			for (int i=1;i<=bg;i++) ans+=a[n-i+1];
			printf("%d \n",ans);
			continue;
		}
		for (int i=1;i<=n;i++){
			ans+=d[i];
		}
		if (an<=bg&&bn<=bg&&cn<=bg){
			printf("%d \n",ans);
			continue;
		}
		if (an>bg){
			int num=an-bg;
			for (int i=1;i<=num;i++){
				ans-=al[i];
			}
			printf("%d \n",ans);
			continue;
		}
		if (bn>bg){
			int num=bn-bg;
			for (int i=1;i<=num;i++){
				ans-=bl[i];
			}
			printf("%d \n",ans);
			continue;
		}
		if (cn>bg){
			int num=cn-bg;
			for (int i=1;i<=num;i++){
				ans-=cl[i];
			}
			printf("%d \n",ans);
			continue;
		}
	}
	return 0;
}
