#include<bits/stdc++.h>
using namespace std;
long long int n,m,k;
struct lo{
	int x,y,num,xug;
}a[1000000];
long long int b[1000000];
long long int ans=0;
long long int d[1000000];
long long int e[1000000];
long long int road[1000000];
void jiancha(long long w){
	for(int i=1;i<=n;i++){
		int lu=a[i].num;
		int cun=e[w]+b[a[i].x]+b[a[i].y];
		if(cun<=lu){
			d[a[i].xug]-=1;
			d[w]+=1;
			a[i].xug=w;
			a[i].num=cun-e[w];
			
		}
	}
}
int find(int x){
	return road[x]=(road[x]==x?x:find(road[x]));
} 
void lianjei(long long int x){
	for(int i=1;i<=n;i++){
		if(find(a[i].x)!=find(a[i].y)){
			if(a[i].x<a[i].y){
				road[a[i].y]=a[i].x;
			}else{
				road[a[i].x]=a[i].y;
			}
			ans+=a[i].num;
		}
	}
}
bool cmd(lo x,lo y){
	return x.num<y.num;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","W",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].num;
		a[i].xug=0;
		road[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>e[i];
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		jiancha(i);
	}
	sort(a+1,a+1+n,cmd);
	lianjei(1);
	for(int i=1;i<=k;i++){
		if(d[i]>0){
			ans+=e[i];
		}
	}
	cout<<ans;
	return 0;
} 
