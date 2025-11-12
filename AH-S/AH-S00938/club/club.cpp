#include <bits/stdc++.h>
using namespace std;
struct node{
	int yi;
	int er;
	int san;
}a[100001];
struct nodee{
	int id;
	int p;
	int t;
	int tt;
	int ttt;
}b[100001],c[100001],d[100001];
bool cmp(nodee a1,nodee a2){
	return a1.t<a2.t;
}
bool cmpp(nodee a1,nodee a2){
	return a1.ttt<a2.ttt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k;
	scanf("%d",&k);
	while(k--){
		int n;
		scanf("%d",&n);
		bool flag=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].yi,&a[i].er,&a[i].san);
			if(a[i].san!=0){
				flag=0;
			}
		}
		if(n==2){
			int s1=0,ss1=0,s2=0,ss2=0,id1,id2;
			if(a[1].yi>a[1].er){
				if(a[1].yi>a[1].san){
					s1=a[1].yi;
					id1=1;
					if(a[1].er>a[1].san){
						ss1=a[1].er;
					}
					else{
						ss1=a[1].san;
					}
				}
				else{
					s1=a[1].san;
					id1=3;
					ss1=a[1].yi;
				}
			}
			else{
				if(a[1].er>a[1].san){
					s1=a[1].er;
					id1=2;
					if(a[1].yi>a[1].san){
						ss1=a[1].yi;
					}
					else{
						ss1=a[1].san;
					}
				}
				else{
					s1=a[1].san;
					id1=3;
					ss1=a[1].er;
				}
			}
			if(a[2].yi>a[2].er){
				if(a[2].yi>a[2].san){
					s2=a[2].yi;
					id2=1;
					if(a[2].er>a[2].san){
						ss2=a[2].er;
					}
					else{
						ss2=a[2].san;
					}
				}
				else{
					s2=a[2].san;
					id2=3;
					ss2=a[2].yi;
				}
			}
			else{
				if(a[2].er>a[2].san){
					s2=a[2].er;
					id2=2;
					if(a[2].yi>a[2].san){
						ss2=a[2].yi;
					}
					else{
						ss2=a[2].san;
					}
				}
				else{
					s2=a[2].san;
					id2=3;
					ss2=a[2].er;
				}
			}
			//cout<<s1<<" "<<ss1<<" "<<s2<<" "<<ss2<<endl;
			//cout<<id1<<" "<<idd1<<" "<<id2<<" "<<idd2<<endl;
			int ans=0;
			if(id1!=id2){
				ans=s1+s2;
			}
			else{
				ans=max(ss1+s2,s1+ss2);
			}
			printf("%d\n",ans);
		}
		else if(flag==1){
			int s=0,ss=0;
			for(int i=1;i<=n;i++){
				if(a[i].yi>a[i].er){
					b[++s].p=a[i].yi;
					b[s].id=i;
					b[s].t=a[i].yi-a[i].er;
				}
				else{
					c[++ss].p=a[i].er;
					c[ss].id=i;
					c[ss].t=a[i].er-a[i].yi;
				}
			}
			long long ans=0;
			for(int i=1;i<=s;i++){
				ans+=b[i].p;
			}
			for(int i=1;i<=ss;i++){
				ans+=c[i].p;
			}
			//cout<<ans<<endl;
			if(s==ss){
				printf("%lld\n",ans);
			}
			else if(s>ss){
				sort(b+1,b+s+1,cmp);
				for(int i=1;i<=s-(n/2);i++){
					ans-=b[i].t;
				}
				printf("%lld\n",ans);
			}
			else{
				sort(c+1,c+ss+1,cmp);
				//cout<<ss-s+1<<endl;
				for(int i=1;i<=ss-(n/2);i++){
					ans-=c[i].t;
				}
				printf("%lld\n",ans);
			}
		}
		else{
			int s=0,ss=0,sss=0;
			for(int i=1;i<=n;i++){
				if(a[i].yi>a[i].er&&a[i].yi>a[i].san){
					b[++s].p=a[i].yi;
					b[s].t=a[i].yi-a[i].er;
					b[s].tt=a[i].yi-a[i].san;
					if(b[s].t>b[s].tt){
						b[s].ttt=b[s].tt;
						b[s].id=3;
					}
					else{
						b[s].ttt=b[s].t;
						b[s].id=2;
					}
				}
				if(a[i].er>a[i].yi&&a[i].er>a[i].san){
					c[++ss].p=a[i].er;
					c[s].t=a[i].er-a[i].yi;
					c[s].tt=a[i].er-a[i].san;
					if(c[ss].t>c[ss].tt){
						c[ss].ttt=c[s].tt;
						c[ss].id=3;
					}
					else{
						c[ss].ttt=c[s].t;
						c[ss].id=2;
					}
				}
				if(a[i].san>a[i].yi&&a[i].san>a[i].er){
					d[++sss].p=a[i].san;
					d[sss].t=a[i].san-a[i].yi;
					d[sss].tt=a[i].san-a[i].er;
					if(d[sss].t>d[sss].tt){
						d[sss].ttt=d[sss].tt;
						d[sss].id=3;
					}
					else{
						d[sss].ttt=d[sss].t;
						d[sss].id=2;
					}
				}
			}
			int q;
			long long ans=0;
			q=n/2;
			for(int i=1;i<=s;i++){
				ans+=b[i].p;
			}
			for(int i=1;i<=ss;i++){
				ans+=c[i].p;
			}
			for(int i=1;i<=sss;i++){
				ans+=d[i].p;
			}
			if(s<=q&&ss<=q&&sss<=q){
				printf("%lld\n",ans);
			}
			else{
				if(s>q){
					sort(b+1,b+s+1,cmpp);
					for(int i=1;i<=s-q;i++){
						ans-=b[i].ttt;
						/*if(b[i].id==2){
							c[++ss].ttt=abs(b[i].t-b[i].tt);
							c[ss].id=3;
						}
						else{
							d[++sss].ttt=abs(b[i].t-b[i].tt);
							d[sss].id=2;
						}*/
					}
					/*if(ss>q){
						for(int i=1;i<=ss;i++){
							if(c[i].id==1){
								c[i].id=3;
								c[i].ttt=max(c[i].t,c[i].tt);
							}
						}
						sort(c+1,c+ss+1,cmpp);
						for(int i=1;i<=ss-1;i++){
							ans-=c[i].ttt;
						}
					}
					if(sss>q){
						
					}*/
				}
				if(ss>q){
					sort(c+1,c+ss+1,cmpp);
					for(int i=1;i<=ss-q;i++){
						ans-=c[i].ttt;
					}
				}
				if(sss>q){
					sort(d+1,d+sss+1,cmpp);
					for(int i=1;i<=sss-q;i++){
						ans-=d[i].ttt;
					}
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
