#include<bits/stdc++.h>

using namespace std;

long long n,m,k,sum=0;
struct R{
	int u,v,w;
};
int fa[10011];
bool cmp(R s1,R s2){
	return s1.w<s2.w;
}

int f_f(int x,int c){
	if(fa[x]==x||fa[fa[x]]==x)return x;
	else return f_f(fa[x],c+1);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	R a[2*m+n*k*2];
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a[i].u,a[i].v,a[i].w);
		a[m+i].u=a[i].v;
		a[m+i].v=a[i].u;
		a[m+i].w=a[i].w;
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			int a1;
			scanf(" %d",&a1);
			a[2*m-1+i*n-n+j].u=n+i;
			a[2*m-1+i*n-n+j].v=j;
			a[2*m-1+i*n-n+j].w=a1+c;
			a[2*m-1+i*n-n+j+n*k].u=j;
			a[2*m-1+i*n-n+j+n*k].v=n+i;
			a[2*m-1+i*n-n+j+n*k].w=a1+c;
		}
	}
	sort(a,a+2*m+n*k*2-1,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int num=1,cnt=0;
	while(num<=n+k&&cnt<2*m+n*k*2){
		if(f_f(a[cnt].u,0)!=f_f(a[cnt].v,0)){
			sum+=a[cnt].w;
			fa[a[cnt].u]=min(a[cnt].u, a[cnt].v);
			fa[a[cnt].v]=min(a[cnt].u, a[cnt].v);
			num++;
		}
		cnt++;
	}
	cout<<sum;
	return 0;
}
