//GZ-S00150 毕节梁才学校 张哲铭
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
int T,n;
struct REN{
	int x;
	int y;
	int id;
	int f;
}a[3000000+10];
bool cmp(REN a,REN b){
	return a.x>b.x;
}
bool v[300000+10];
int cnt;
LL ans;
int c[15];
void init(){
	memset(c,0,sizeof(c));
	cnt=0;
	ans=0;
	memset(v,false,sizeof(v));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		if(n==2){
			int x,y,z;
			int xx,yy,zz;
			scanf("%d%d%d%d%d%d",&x,&y,&z,&xx,&yy,&zz);
			int ma=-0x3f3f3f3f;
			ma=max(ma,x+yy);
			ma=max(ma,x+zz);
			ma=max(ma,y+xx);
			ma=max(ma,y+zz);
			ma=max(ma,z+xx);
			ma=max(ma,z+yy);
			printf("%d\n",ma);
			continue;
		} 
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i+n].x,&a[i+n+n].x);
			a[i].y=i;
			a[i+n].y=i;
			a[i+n+n].y=i;
			
			a[i].id=1;
			a[i+n].id=2;
			a[i+n+n].id=3;
		}
		
		sort(a+1,a+n*3+1,cmp);
		for(int i=1;cnt<n;i++){
			if(!v[a[i].y]&&c[a[i].id]<n/2){
				v[a[i].y]=true,cnt++,c[a[i].id]++;
				ans+=a[i].x;
				a[i].f=i;
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
