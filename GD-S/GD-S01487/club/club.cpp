#include<bits/stdc++.h>
using namespace std;
int a[100001][3];
struct shu{
	int maxn,cha,id,id2;
}d[100001];
bool cmp(shu x,shu y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x=0,y=0,z=0,sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int mm=max(a[i][0],max(a[i][1],a[i][2]));
			if(mm==a[i][0]) d[i].id=1;
			else if(mm==a[i][1]) d[i].id=2;
			else d[i].id=3;
			d[i].cha=mm-min(a[i][0],min(a[i][1],a[i][2]));
			d[i].maxn=mm;
			d[i].id2=i;
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(d[i].id==1&&x>=n/2){
				d[i].maxn=max(a[d[i].id2][1],a[d[i].id2][2]);
				a[d[i].id2][0]=-1;
			}
			if(d[i].id==2&&y>=n/2){
				d[i].maxn=max(a[d[i].id2][0],a[d[i].id2][2]);
				a[d[i].id2][1]=-1;
			}
			if(d[i].id==3&&z>=n/2){
				d[i].maxn=max(a[d[i].id2][0],a[d[i].id2][1]);
				a[d[i].id2][2]=-1;
			}
			sum+=d[i].maxn;
			if(d[i].id==1) x++;
			else if(d[i].id==2) y++;
			else z++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
