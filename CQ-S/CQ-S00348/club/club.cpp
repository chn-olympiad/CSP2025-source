#include<bits/stdc++.h>
using namespace std;
int T,n,da[100005],db[100005],dc[100005],ta,tb,tc;
struct node{
	int a,b,c;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ta=tb=tc=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			int v=max(a[i].a,max(a[i].b,a[i].c));
			ans+=v;
			if(a[i].a==v)da[++ta]=max(a[i].b,a[i].c)-v;
			else if(a[i].b==v)db[++tb]=max(a[i].a,a[i].c)-v;
			else dc[++tc]=max(a[i].a,a[i].b)-v;
		}
		if(ta>(n>>1)){
			sort(da+1,da+1+ta);
			for(int i=ta;i>(n>>1);i--)ans+=da[i];
		}
		if(tb>(n>>1)){
			sort(db+1,db+1+tb);
			for(int i=tb;i>(n>>1);i--)ans+=db[i];
		}
		if(tc>(n>>1)){
			sort(dc+1,dc+1+tc);
			for(int i=tc;i>(n>>1);i--)ans+=dc[i];
		}
		printf("%d\n",ans); 
	}
}
