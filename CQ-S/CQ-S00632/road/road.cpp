#include<bits/stdc++.h>
using namespace std;
int n,m,t,b[11][10010],c[100010],d[100010],maxn,top,top2,f[100010];
long long ans;
pair<int,pair<int,int>>a[1000010],a1[1000010];
vector<pair<int,pair<int,int>>>e[1029];
inline int cz(int x){
	if(x==c[x]){
		return x;
	}
	return c[x]=cz(c[x]);
}
inline void dfs(int i,long long s){
	if(s>=ans){
		return;
	}
	if(i==t+1){
//		printf("*%d* ",ss);
		for(int j=1;j<=n+t;j++){
			c[j]=j;
		}
		int s1=0,s2=n,ss=0;
		for(int j=1;j<=t;j++){
			s2+=d[j];
			ss+=d[j]*(1<<(j-1));
//			printf("[%d] ",d[j]);
		}
//		printf("::%d::",ss);
		int xx=0,yy=1,len=e[ss].size()-1;
		top=0;
		for(;xx<=len||yy<=top2;){
			if(xx<=len&&(yy>top2||e[ss][xx]<a1[yy])){
				a[++top]=e[ss][xx];
				xx++;
			}
			else{
				a[++top]=a1[yy];
				yy++;
			}
		}
//		for(int j=1;j<=top;j++){
//			printf("?%d %d %d? ",a[j].first,a[j].second.first,a[j].second.second);
//		}
//		printf("\n");
		for(int asdf=1;asdf<=top&&s1<s2-1;asdf++){
			pair<int,pair<int,int>>j=a[asdf];
			int x=j.second.first,y=j.second.second;
			if(cz(x)!=cz(y)){
				s1++;
				s+=j.first;
				x=cz(x),y=cz(y);
				c[x]=y;
			}
			if(s>=ans){
				break;
			}
		}
		ans=min(ans,s);
		return;
	}
	d[i]=0;
	dfs(i+1,s);
	d[i]=1;
	dfs(i+1,s+b[i][0]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	return 0;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[++top]={z,{x,y}};
	}
//	return 0;
	for(int i=1;i<=t;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
//	return 0;
	sort(a+1,a+top+1);
	for(int i=1;i<=n;i++){
		c[i]=i;
	}
	for(int asdf=1;asdf<=top;asdf++){
		pair<int,pair<int,int>>j=a[asdf];
		int x=j.second.first,y=j.second.second;
		if(cz(x)!=cz(y)){
			a1[++top2]=j;
			maxn=max(maxn,j.first);
			ans+=j.first;
			x=cz(x),y=cz(y);
			c[x]=y;
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]<=maxn){
				e[(1<<t)-1].push_back({b[i][j],{n+i,j}});
//				printf("?%d?\n",(int)e[(1<<t)-1].size());
			}
		}
	}
//	printf("dffd");
	sort(e[(1<<t)-1].begin(),e[(1<<t)-1].end());
	for(int i=(1<<t)-1;i>=0;i--){
		for(int j=1;j<=t;j++){
			if((i&(1<<(j-1)))&&!f[i-(1<<(j-1))]){
				f[i-(1<<(j-1))]=1;
				for(auto k:e[i]){
//					printf("?%d?",k.second.first);
					if(k.second.first-n!=j){
//						printf("?");
						e[i-(1<<(j-1))].push_back(k);
					}
				}
			}
		}
	}
//	return 0;
//	for(int i=0;i<(1<<t);i++){
////		printf("(Y(H(*H)))");
//		for(auto j:e[i]){
//			printf("*%d %d %d*",j.first,j.second.first,j.second.second);
//		}
//		printf("\n");
//	}
//	printf("FDF");
	dfs(1,0);
//	printf("3232");
	printf("%lld",ans);
//	for(;;);
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
