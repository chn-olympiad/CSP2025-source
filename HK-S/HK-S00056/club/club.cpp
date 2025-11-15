#include <bits/stdc++.h>
using namespace std;
int t,n,anum,bnum,cnum,ans,ac,bc,cc;
struct node{
	int a,b,c;
}s[1000010];
struct edge{
	int id,second;
}fa[1000010],fb[1000010],fc[1000010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		anum=bnum=cnum=n/2,ans=0;
		ac=bc=cc=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			if(s[i].a==s[i].b && s[i].a==s[i].c){
				if(anum>=bnum && anum>=cnum){
					ans+=s[i].a,anum--;
					ac++; fa[ac].id=i; fa[ac].second=max(s[i].b,s[i].c);
				}
				else if(bnum>anum && bnum>cnum){
					ans+=s[i].b,bnum--;
					bc++; fb[bc].id=i; fb[bc].second=max(s[i].a,s[i].c);
				}
				else{
					ans+=s[i].c,cnum--;
					cc++; fc[cc].id=i; fa[cc].second=max(s[i].b,s[i].a);
				}
			}
			else if(s[i].a==s[i].b){
				if(anum<bnum){
					ans+=s[i].b,bnum--;
					bc++; fb[bc].id=i; fb[bc].second=max(s[i].a,s[i].c);
				}
				else{
					ans+=s[i].a,anum--;
					ac++; fa[ac].id=i; fa[ac].second=max(s[i].b,s[i].c);
				}
			}
			else if(s[i].a==s[i].c){
				if(anum<cnum){
					ans+=s[i].c,cnum--;
					cc++; fc[cc].id=i; fc[cc].second=max(s[i].a,s[i].b);
				}
				else{
					ans+=s[i].a,anum--;
					ac++; fa[ac].id=i; fa[ac].second=max(s[i].b,s[i].c);
				}
			}
			else if(s[i].b==s[i].c){
				if(bnum<cnum){
					ans+=s[i].c,cnum--;
					cc++; fc[cc].id=i; fc[cc].second=max(s[i].b,s[i].a);
				}
				else{
					ans+=s[i].b,bnum--;
					bc++; fb[bc].id=i; fb[bc].second=max(s[i].a,s[i].c);
				}
			}
			if(s[i].a>s[i].b && s[i].a>s[i].c){
				if(anum!=0){
					ans+=s[i].a;
					anum--;
					ac++;
					fa[ac].id=i; fa[ac].second=max(s[i].b,s[i].c);
				}
				else{
					int xid=-1e9,maxn=-1e9;
					for(int j=1;j<=ac;j++){
						int ld=fa[j].second+s[i].a-s[fa[j].id].a;
						if(ld>0){
							if(ld>maxn) maxn=ld,xid=j;
						}
					}
					if(xid==-1e9){
						if(s[i].b>s[i].c){
							ans+=s[i].b;
						}
						else{
							ans+=s[i].c;
						}
					}
					else{
						ans+=s[i].a+fa[xid].second-s[fa[xid].id].a;
						fa[xid].id=i; fa[xid].second=max(s[i].b,s[i].c);
					}
				}
			}// max=a
			else if(s[i].b>s[i].a && s[i].b>s[i].c){
				if(bnum!=0){
					ans+=s[i].b;
					bnum--;
					bc++;
					fb[bc].id=i; fb[bc].second=max(s[i].a,s[i].c);
				}
				else{
					int xid=-1e9,maxn=-1e9;
					for(int j=1;j<=bc;j++){
						int ld=fb[j].second+s[i].b-s[fb[j].id].b;
						if(ld>0){
							if(ld>maxn) maxn=ld,xid=j;
						}
					}
					if(xid==-1e9){
						if(s[i].a>s[i].c){
							ans+=s[i].a;
						}
						else{
							ans+=s[i].c;
						}
					}
					else{
						ans+=s[i].b+fb[xid].second-s[fb[xid].id].b;
						fb[xid].id=i; fb[xid].second=max(s[i].a,s[i].c);
					}
				}
			}//max=b
			else{
				if(cnum!=0){
					ans+=s[i].c;
					cnum--;
					cc++;
					fc[cc].id=i; fc[cc].second=max(s[i].b,s[i].a);
				}
				else{
					int xid=-1e9,maxn=-1e9;
					for(int j=1;j<=cc;j++){
						int ld=fc[j].second+s[i].c-s[fc[j].id].c;
						if(ld>0){
							if(ld>maxn) maxn=ld,xid=j;
						}
					}
					if(xid==-1e9){
						if(s[i].a>s[i].b){
							ans+=s[i].a;
						}
						else{
							ans+=s[i].b;
						}
					}
					else{
						ans+=s[i].c+fc[xid].second-s[fc[xid].id].c;
						fc[xid].id=i; fc[xid].second=max(s[i].b,s[i].a);
					}
				}
			}//max=c
			//printf("%d ",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
