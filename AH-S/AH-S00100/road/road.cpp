#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}sum[5000000];
int f[100000];
int ge[100000];
bool cmp(node x,node y){
	return x.c<y.c;
}
int find(int x){
	if (f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
void check(int x,int y){
	f[find(y)]=find(x);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,ans,num,k;
	cin>>n>>m>>k;
	
	for(int i=1;i<=n+2*k;i++)
		f[i]=i;
	
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&sum[i].a,&sum[i].b,&sum[i].c);
	
	for(int i=1;i<=k;i++){
		scanf("%d",&num);
		for(int w=1;w<=n;w++){
			scanf("%d",&ge[w]);
			sum[m].a=n+i;
			sum[m].b=w;
			sum[m].c=ge[w];
			m++;
		}
	}
	sort(sum,sum+m,cmp);
	ans=0;num=0;
	for(int i=0;i<m;i++){
		if (find(sum[i].a)!=find(sum[i].b)){
			ans+=sum[i].c;num++;
			check(sum[i].a,sum[i].b);
		}
		if (num>=n+k-1) break;
	}
	cout<<ans;
	return 0;
}
