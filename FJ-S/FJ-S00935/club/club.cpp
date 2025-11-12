#include<bits/stdc++.h>
using namespace std;

int T,n,t[5],ans;
struct str{
	int a[5],b,c,d;
}v[100005];

bool cmp(str a,str b){
	return a.d>b.d;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);while(T--){
		scanf("%d",&n);ans=t[1]=t[2]=t[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) scanf("%d",&v[i].a[j]);
			int x=max(max(v[i].a[1],v[i].a[2]),v[i].a[3]),y=min(min(v[i].a[1],v[i].a[2]),v[i].a[3]),z,p=0,q=0;
			for(int j=1;j<=3;j++){
				if(v[i].a[j]==x&&p==0) p=v[i].c=j;
				else if(v[i].a[j]==y&&q==0) q=j; 
			}
			for(int j=1;j<=3;j++) if(j!=p&&j!=q) z=v[i].a[j],v[i].b=j;v[i].d=x-z;
		}
		sort(v+1,v+1+n,cmp);
		for(int i=1;i<=n;i++){
			ans+=v[i].a[v[i].c];
			if(t[v[i].c]==n/2) ans-=v[i].d;else t[v[i].c]++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
