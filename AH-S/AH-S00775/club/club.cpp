#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
struct node{
	int x,y,z;
	int maxn,minn;
	int fm,fn;
	int mix,rmid;
}a[1000005];
int f[4];
bool cmp(node p,node q){
	if(p.rmid==q.rmid) return p.maxn>q.maxn;
	return p.rmid>q.rmid;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		for(int i=1;i<=4;i++) f[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
			a[i].minn=min(a[i].x,min(a[i].y,a[i].z));
			if(a[i].maxn==a[i].x) a[i].fm=1;
			else if(a[i].maxn==a[i].y) a[i].fm=2;
			else a[i].fm=3;
			if(a[i].minn==a[i].x) a[i].fn=1;
			else if(a[i].minn==a[i].y) a[i].fn=2;
			else a[i].fn=3;
			a[i].mix=a[i].x+a[i].y+a[i].z;
			a[i].rmid=2*a[i].maxn+a[i].minn-a[i].mix;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(f[a[i].fm]+1<=n/2){
				ans+=a[i].maxn;
				f[a[i].fm]++;
			}else if(f[6-a[i].fm-a[i].fn]+1<=n/2){
				ans+=a[i].mix-a[i].maxn-a[i].minn;
				f[6-a[i].fm-a[i].fn]++;
			}else{
				ans+=a[i].minn;
				f[a[i].fn]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
