#include<bits/stdc++.h>
#define N 100005

using namespace std;

int t,c1,c2,c3,t1[N],t2[N];
struct man{
	int a,b,c,zh;
	bool vis;
}e[N];
struct O{
	int t[N];
}cl[4];

bool cmpd(int x,int y){
	return e[x].zh>e[y].zh;
}
bool cmpx(int x,int y){
	return e[x].zh<e[y].zh;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		c1=c2=c3=0;
		int n,ans=0;
		scanf("%d",&n);
		int lim=n>>1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
			e[i].zh=e[i].a-e[i].b;
		}
			
		
		for(int i=1;i<=n;i++){
			int a=e[i].a,b=e[i].b,c=e[i].c;
				if(a>b){
					ans+=a;
					c1++;
					t1[c1]=i;
//					cl[1].t[c1]=i;
				}else{
					ans+=b;
					c2++;
					t2[c2]=i;
//					cl[2].t[c2]=i;
				}
				
		}
		
		
		int an[4];
		bool fat[4];
		an[1]=c1,an[2]=c2,an[3]=c3;
		for(int i=1;i<=3;i++){
			if(an[i]>lim)fat[i]=false;
			else fat[i]=true;
		}
		if(fat[1]==false){
			sort(t1+1,t1+1+c1,cmpx);
			int du=c1-lim;
			for(int i=1;i<=du;i++){
				ans-=e[t1[i]].zh;
			}
		}else if(fat[1]==true){
			sort(t2+1,t2+1+c2,cmpd);
			int du=c2-lim;
			for(int i=1;i<=du;i++){
				ans+=e[t2[i]].zh;
			}
		}
		cout<<ans<<endl;
		
	}
	
	
	return 0;
}


















