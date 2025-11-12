#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ma[N],zc[N],ans,tmp,cb[N],st;
struct node{
	int a,b,c;
}q[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;st=0;tmp=0;
		zc[1]=zc[2]=zc[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			ma[i]=0;
			scanf("%d %d %d",&q[i].a,&q[i].b,&q[i].c);
			if(q[i].a>q[i].b&&q[i].a>q[i].c) ma[i]=1,zc[1]++;
			if(q[i].b>q[i].a&&q[i].b>q[i].c) ma[i]=2,zc[2]++;
			if(q[i].c>q[i].b&&q[i].c>q[i].a) ma[i]=3,zc[3]++;
		}
		if(zc[1]<=n/2&&zc[2]<=n/2&&zc[3]<=n/2){
			for(int i=1;i<=n;i++) ans+=max(q[i].a,max(q[i].b,q[i].c));
			printf("%d\n",ans);
			continue;
		}
		else if(zc[1]>n/2) tmp=1;
		else if(zc[2]>n/2) tmp=2;
		else if(zc[3]>n/2) tmp=3;
		for(int i=1;i<=n;i++){
			if(ma[i]==tmp){
				st++;
				if(tmp==1) cb[st]=min(q[i].a-q[i].b,q[i].a-q[i].c);
				if(tmp==2) cb[st]=min(q[i].b-q[i].a,q[i].b-q[i].c);
				if(tmp==3) cb[st]=min(q[i].c-q[i].b,q[i].c-q[i].a);
//				cout<<cb[st]<<" ";
			}
			ans+=max(q[i].a,max(q[i].b,q[i].c));
		}
		sort(cb+1,cb+st+1);
		for(int i=1;i<=st-(n/2);i++) ans-=(cb[i]);
		printf("%d\n",ans);
	}
	return 0;
}
