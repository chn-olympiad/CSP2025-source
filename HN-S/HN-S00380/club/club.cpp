#include<bits/stdc++.h>
using namespace std;
const int lb=100010;
struct hg{
	int h,id;
}x[lb],y[lb],z[lb];
bool cmp(hg a,hg b){
	if(a.h!=b.h) return a.h>b.h;
	return a.id<b.id;
}
int t,n,a[lb][4],v[lb]; long long s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		s=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i].h,&y[i].h,&z[i].h);
			x[i].id=y[i].id=z[i].id=i;
		}
		sort(x+1,x+1+n,cmp);
		sort(y+1,y+1+n,cmp);
		sort(z+1,z+1+n,cmp);
		memset(v,0,sizeof(v));
		for(int i=1;i<=n/2;i++)
		  if(!v[x[i].id]) s+=x[i].h,v[x[i].id]=1;
		  else if(x[i].h>x[v[x[i].id]].h)
			s += x[i].h-x[v[x[i].id]].h,v[x[i].id]=1;
		for(int i=1;i<=n/2;i++)
		  if(!v[y[i].id]) s+=y[i].h,v[y[i].id]=2;
		  else if(y[i].h>y[v[y[i].id]].h)
		    s += y[i].h-y[v[y[i].id]].h,v[y[i].id]=2;
		for(int i=1;i<=n/2;i++)
		  if(!v[z[i].id]) s+=z[i].h,v[z[i].id]=3;
		  else if(z[i].h>z[v[z[i].id]].h)
		    s += z[i].h-z[v[z[i].id]].h,v[z[i].id]=3;
		for(int i=1;i<=n/2;i++)
		  if(x[i].h>x[v[x[i].id]].h)
			s += x[i].h-x[v[x[i].id]].h,v[x[i].id]=1;
		printf("%lld\n",s);
	}
	return 0;
}
