#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N],d[N],ans,s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=2e9;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		s=0;
		for(int i=1;i<=n;i++)
			d[i]=max(b[i],c[i])-a[i],s+=max(b[i],c[i]);
		sort(d+1,d+n+1);
		for(int i=1;i<=n>>1;i++){
			if(d[i]>=0)break;
			s-=d[i];
		}
		ans=min(ans,s);
		s=0;
		for(int i=1;i<=n;i++)
			d[i]=max(a[i],c[i])-b[i],s+=max(a[i],c[i]);
		sort(d+1,d+n+1);
		for(int i=1;i<=n>>1;i++){
			if(d[i]>=0)break;
			s-=d[i];
		}
		ans=min(ans,s);
		s=0;
		for(int i=1;i<=n;i++)
			d[i]=max(a[i],b[i])-c[i],s+=max(a[i],b[i]);
		sort(d+1,d+n+1);
		for(int i=1;i<=n>>1;i++){
			if(d[i]>=0)break;
			s-=d[i];
		}
		ans=min(ans,s);
		printf("%d\n",ans);
	}
	
	return 0;
} 
