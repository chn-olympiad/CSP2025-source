//1-club
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int n;
int b[10];
long long ans=0,mx=0;
bool cmpx(node x,node y){
	return x.x>y.x;
}
bool cmpy(node x,node y){
	return x.y>y.y;
}
void f(int x){
	if(x>n){
		mx=max(mx,ans);
		return;	
	}
	for(int i=1;i<=3;i++)
		if(b[i]<n/2){
			b[i]++;
			int tp=(i==1?a[x].x:(i==2?a[x].y:a[x].z));
			ans+=tp;
			f(x+1);
			ans-=tp;
			b[i]--;
		}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		bool by=1,bz=1;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			a[i]={x,y,z};
			if(y)by=0;
			if(z)bz=0;
		}
		if(by&&bz){
			sort(a+1,a+1+n,cmpx);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			printf("%lld\n",ans);
			continue;
		}
		if(bz){
			for(int i=1;i<=n;i++){
				int mn=min(a[i].x,a[i].y);
				a[i].x-=mn,a[i].y-=mn;
				ans+=mn;
			}
			sort(a+1,a+1+n,cmpx);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			sort(a+1,a+1+n,cmpy);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].y;
			printf("%lld\n",ans);	
			continue;
		}
		mx=0;
		f(1);
		printf("%lld\n",mx);
	}
	return 0;
}
