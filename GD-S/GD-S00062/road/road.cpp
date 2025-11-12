#include<bits/stdc++.h>
using namespace std;
struct node{
	int f,t,v;
}e[1100001];
long long n,m,k,f,t,st,r,num,ansp,ans=9223372036854775807,c[11],rd[1025],fa[10011];
bool cmp(node a,node b){
	return a.v<b.v;
}
int find(int a){
	if(fa[a]==a){
		return a;
	}
	return fa[a]=find(fa[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	st=clock();
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].f>>e[i].t>>e[i].v;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			t=m+(i-1)*n+j;
			cin>>e[t].v;
			e[t].f=n+i;
			e[t].t=j;
		}
	}
	sort(e+1,e+m+n*k+1,cmp);
	for(int i=1;i<=pow(2,k);i++){
		rd[i]=i-1;
	}
	for(int i=1;i<=pow(2,k);i++){
		swap(rd[i],rd[rand()%(int)pow(2,k)+1]);
	}
	for(int i=0;(i<=pow(2,k))&&(clock()-st<0.98*CLOCKS_PER_SEC);i++){
		num=n;
		ansp=0;
		for(int j=1;j<=k;j++){
			if((rd[i]/(int)pow(2,j-1))%2){
				ansp+=c[j];
				num++;
			}
		}
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int j=1;j<=m+n*k;j++){
			f=find(e[j].f);
			t=find(e[j].t);
			if((f!=t)&&((f<=n)||(rd[i]/(int)pow(2,f-n-1))%2)){
				fa[f]=t;
				ansp+=e[j].v;
				if(ansp>=ans){
					break;
				}
				num--;
			}
			if(!num){
				break;
			}
		}
		ans=min(ans,ansp);
	}
	cout<<ans;
	return 0;
}
