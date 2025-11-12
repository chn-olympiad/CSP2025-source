#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n,v[N][3],cnt[3],a[N],b[N],c[N];
ll ans;

void clr(){
	ans=0ll;
	for(int i=1;i<=n;i++) v[i][0]=v[i][1]=v[i][2]=a[i]=b[i]=c[i]=0;
	cnt[0]=cnt[1]=cnt[2]=n=0;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		ans=0ll;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
			if(v[i][0]>=v[i][1]&&v[i][0]>=v[i][2]){
				ans+=v[i][0];
				cnt[0]++,a[cnt[0]]=v[i][0]-max(v[i][1],v[i][2]);
			}
			else if(v[i][1]>=v[i][0]&&v[i][1]>=v[i][2]){
				ans+=v[i][1];
				cnt[1]++,b[cnt[1]]=v[i][1]-max(v[i][0],v[i][2]);
			}
			else{
				ans+=v[i][2];
				cnt[2]++,c[cnt[2]]=v[i][2]-max(v[i][0],v[i][1]);
			}
		}
		if(cnt[0]>n/2){
			sort(a+1,a+cnt[0]+1);
			for(int i=1;i<=cnt[0]-n/2;i++) ans-=a[i];
		}
		else if(cnt[1]>n/2){
			sort(b+1,b+cnt[1]+1);
			for(int i=1;i<=cnt[1]-n/2;i++) ans-=b[i];
		}
		else if(cnt[2]>n/2){
			sort(c+1,c+cnt[2]+1);
			for(int i=1;i<=cnt[2]-n/2;i++) ans-=c[i];
		}
		printf("%lld\n",ans);
		clr();
	}
	return 0;
}
