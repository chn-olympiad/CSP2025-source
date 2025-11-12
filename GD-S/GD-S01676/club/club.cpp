#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
int n,a,b,c,T;
int cnt[5];
int fir[N],sec[N],thr[N];
ll ans;
void init(){
	ans=0;
	cnt[1]=0;
	cnt[2]=0;
	cnt[3]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c) fir[++cnt[1]]=min(a-b,a-c),ans+=a;
			else if(b>=a&&b>=c) sec[++cnt[2]]=min(b-a,b-c),ans+=b;
			else if(c>=a&&c>=b) thr[++cnt[3]]=min(c-a,c-b),ans+=c;
		}
		if(cnt[1]*2>n){
			sort(fir+1,fir+1+cnt[1]);
			for(int i=1;(cnt[1]-i)*2>=n;i++) ans-=fir[i];
		}
		if(cnt[2]*2>n){
			sort(sec+1,sec+1+cnt[2]);
			for(int i=1;(cnt[2]-i)*2>=n;i++) ans-=sec[i];
		}
		if(cnt[3]*2>n){
			sort(thr+1,thr+1+cnt[3]);
			for(int i=1;(cnt[3]-i)*2>=n;i++) ans-=thr[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
