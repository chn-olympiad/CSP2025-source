#include<bits/stdc++.h>
using namespace std;
int t,n,aa,bb,cc,ans;
struct nn{
	int a,b,c;
}p[100005];
bool cmp(nn x,nn y){
	 return x.a+max(y.b,y.c)>max(x.b,x.c)+y.a;
}
bool cmpp(nn x,nn y){
	 return x.b+max(y.a,y.c)>max(x.a,x.c)+y.b;
}
bool cmppp(nn x,nn y){
	 return x.c+max(y.b,y.a)>max(x.b,x.a)+y.c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		aa=0;
		bb=0;
		cc=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
		scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		if(p[i].a>p[i].b&&p[i].a>p[i].c) aa++;
		if(p[i].b>p[i].a&&p[i].b>p[i].c) bb++;
		if(p[i].c>p[i].b&&p[i].c>p[i].a) cc++;	
		}
		if(max(aa,max(bb,cc))<=n/2){
			for(int i=1;i<=n;i++){
				ans+=max(p[i].a,max(p[i].b,p[i].c));
			}
		}else{
			if(aa>bb&&aa>cc){
			sort(p+1,p+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=p[i].a;
			}	
			for(int i=n/2+1;i<=n;i++){
				ans+=max(p[i].b,p[i].c);
			}
			}else if(bb>aa&&bb>cc){
			sort(p+1,p+1+n,cmpp);	
			for(int i=1;i<=n/2;i++){
				ans+=p[i].b;
			}	
			for(int i=n/2+1;i<=n;i++){
				ans+=max(p[i].a,p[i].c);
			}
			}else{
			sort(p+1,p+1+n,cmppp);
			for(int i=1;i<=n/2;i++){
				ans+=p[i].c;
			}	
			for(int i=n/2+1;i<=n;i++){
				ans+=max(p[i].b,p[i].a);
			}	
			}
			
		}
		printf("%d\n",ans);
		
	}
	
	
	
	
	return 0;
}

//退役宣言：这可能是我最后一场csp了，学习信息的这几年很开心，交到了很多朋友，今年我可能要和peanut一样为我的最后一次比赛绽放我最后的烟花了，祝tes，英雄联盟s15战胜lck夺冠 
