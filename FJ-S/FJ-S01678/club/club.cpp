#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,cnt[5],lst[5];
struct node{long long a[5],srt[5],c;}p[100005];
bool cmp(node a,node b){
	return a.a[a.srt[1]]>b.a[b.srt[1]] || a.a[a.srt[1]]==b.a[b.srt[1]]&&a.a[a.srt[2]]>b.a[b.srt[2]];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;
		memset(cnt,0,sizeof cnt);
		memset(lst,0,sizeof lst);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a[1],&p[i].a[2],&p[i].a[3]);
			if(p[i].a[1]>p[i].a[2]&&p[i].a[1]>p[i].a[3]){
				p[i].srt[1]=1;
				if(p[i].a[2]>p[i].a[3]) p[i].srt[2]=2,p[i].srt[3]=3;
				else p[i].srt[2]=3,p[i].srt[3]=2;
			}else if(p[i].a[2]>p[i].a[1]&&p[i].a[2]>p[i].a[3]){
				p[i].srt[1]=2;
				if(p[i].a[1]>p[i].a[3]) p[i].srt[2]=1,p[i].srt[3]=3;
				else p[i].srt[2]=3,p[i].srt[3]=1;
			}else if(p[i].a[3]>p[i].a[1]&&p[i].a[3]>p[i].a[2]){
				p[i].srt[1]=3;
				if(p[i].a[2]>p[i].a[1]) p[i].srt[2]=2,p[i].srt[3]=1;
				else p[i].srt[2]=1,p[i].srt[3]=2;
			}
			p[i].c=p[i].a[p[i].srt[1]]-p[i].a[p[i].srt[2]];
		}
//		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++){
			int nowbig=p[i].srt[1];
			int nowscd=p[i].srt[2];
			int lsti=lst[nowbig];
			int lstscd=p[lsti].srt[2];
			if(cnt[nowbig]<(n>>1)){
				ans+=p[i].a[nowbig],cnt[nowbig]++;
				if(lst[nowbig]==0) lst[nowbig]=i;
				else if(p[i].c<p[lsti].c) lst[nowbig]=i;
			}else{
				if(p[lsti].a[nowbig]+p[i].a[nowscd]<p[lsti].a[lstscd]+p[i].a[nowbig]){
					ans-=p[lsti].c;
					ans+=p[i].a[nowbig];
					cnt[lstscd]++;
					if(p[i].c<p[lsti].c) lst[nowbig]=i;
				}else{
					ans+=p[i].a[nowscd];
					cnt[nowscd]++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
