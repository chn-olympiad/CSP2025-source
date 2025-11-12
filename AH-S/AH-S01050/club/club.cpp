#include<bits/stdc++.h>
using namespace std;
int b[100005];
struct node{
	int x,y,z,maxn,xh,cha;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i,n,ans=0,cnt1=0,cnt2=0,cnt3=0,s=0;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=cnt1=cnt2=cnt3=s=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=a[i].z&&a[i].x>=a[i].y)
				a[i].maxn=a[i].x,a[i].xh=1;
			if(a[i].y>=a[i].z&&a[i].y>=a[i].x)
				a[i].maxn=a[i].y,a[i].xh=2;
			if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
				a[i].maxn=a[i].z,a[i].xh=3;
			a[i].cha=a[i].maxn-(a[i].x+a[i].y+a[i].z-a[i].maxn-min(a[i].x,min(a[i].y,a[i].z)));
		}
		for(i=1;i<=n;i++){
			ans+=a[i].maxn;
			if(a[i].xh==1)
				cnt1++;
			if(a[i].xh==2)
				cnt2++;
			if(a[i].xh==3)
				cnt3++;
		}
		if(cnt1>n/2||cnt2>n/2||cnt3>n/2){
			if(cnt1>n/2){
				for(i=1;i<=n;i++)
					if(a[i].xh==1)
						b[++s]=a[i].cha;
			}
			if(cnt2>n/2){
				for(i=1;i<=n;i++)
					if(a[i].xh==2)
						b[++s]=a[i].cha;
			}
			if(cnt3>n/2){
				for(i=1;i<=n;i++)
					if(a[i].xh==3)
						b[++s]=a[i].cha;
			}
			sort(b+1,b+s+1);
			for(i=1;i<=s-n/2;i++)
				ans-=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
