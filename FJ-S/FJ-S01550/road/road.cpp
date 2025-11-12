#include<bits/stdc++.h>
using namespace std;
const int M=1e6+11;
struct edge{
	int e=0,ne=0,h=-1,w=0,t=0;
	bool b=0,citty=0;
}a[M];
int city[11][M]={};
int idx=0;
int connet[M]={};
void add(int first,int last,int value){
	a[++idx].e =last;
	a[idx].t=first;
	a[idx].ne =a[first].h ;
	a[idx].w =value;
	a[first].h =idx;
	connet[first]++;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		ans+=k;
		add(u,v,k);
		add(v,u,k);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>city[i][j];
		}
	}
	for(int z=1;z<=m-n+1;z++){
		int now=0;
		for(int i=1;i<=idx;i+=2){
			if(a[now].w <=a[i].w ){
				if(connet[a[i].t]==1||connet[a[i].e]==1){
					continue;
				}
				now=i;
				
			}
			
		}
		connet[a[now].t]--;
		connet[a[now].e ]--;
		ans-=a[now].w ;
		a[now].b =1;
		a[now+1].b =1;
	}
	for(int i=1;i<=k;i++){
		if(city[i][0]>=ans){
			continue;
		}
		int max_=city[i][0];
		
		for(int z=1;z<=n-1;z++){
			int now=0;
			for(int j=1;j<=idx;j+=2){
				if(a[j].b ==0&&a[j].citty ==0){
					if(a[now].w <=a[j].w ){
						now=j;
					}
				}
			}
			a[now].citty =1;
			a[now+1].citty =1;
			int tou=a[now].t ;
			if(connet[a[now].t ]!=1){
				int tou=a[now].e ;
			}
			int aft=a[now].w ;
			int bef=0;
			for(int j=1;j<=n;j++){
				if(j!=tou&&aft>=city[i][tou]+city[i][j]){
					aft=city[i][tou]+city[i][j];
					bef=j;
				}
			}
			if(bef!=0){
				connet[a[now].t]--;
				connet[a[now].e]--;
				add(tou,bef,aft);
				add(bef,tou,aft);
				a[idx].citty =1;
				a[idx-1].citty =1;
			}
			
			a[now].b =1;
			a[now+1].b =1;
			
			
			max_+=aft;
		}
		
		if(ans>max_){
			ans=max_;
		}
	}
	cout<<ans;
}
