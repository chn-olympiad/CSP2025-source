#include<bits/stdc++.h>
using namespace std;
#define p pair<int,int>
int n,m,k,x,y,ww,g[100010],w[10][10],dis[10010],f[10010],tl,tr,l,r,fl,fff,c,ss,sum,mi,ans=1e9;
struct stu{
	int u,v,w;
}a[100010];
bool cmp(const stu&x,const stu&y){
	return x.w<y.w;
}
int find(int k){
	if(f[k]==k)return k;
	return f[k]=find(f[k]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>ww;
		a[i]={x,y,ww};
	}
	for(int i=1;i<=k;i++){
		cin>>g[i];
		if(g[i]!=0)fff=1;
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		l=a[i].u,r=a[i].v;
		l=find(l),r=find(r);
		if(l!=r){
			f[l]=r;
			c++;
			sum+=a[i].w;
		}
		if(c==n-1)break;
	}
	if(c==n-1)ans=sum;
	for(int i=1;i<=n;i++)f[i]=i;
	sum=0;
	c=0;
	if(k&&!fff){
		for(int i=1;i<=m;i++){
			mi=1e9;
			l=a[i].u,r=a[i].v;
			tl=l,tr=r;
			for(int j=1;j<=k;j++){
				if(mi>w[j][l]+w[j][r]){
					mi=w[j][l]+w[j][r];
					ss=j;
				}
			}
			l=find(l),r=find(r);
			if(l!=r){
				if(a[i].w>mi){
					f[l]=r;
					c++;
					sum+=mi;
					w[ss][tl]=0;
					w[ss][tr]=0;
				}else{
					f[l]=r;
					c++;
					sum+=a[i].w;					
				}
			}
			if(c==n-1)break;
		}
		cout<<min(sum,ans)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
4 4 0
3 4 4
2 4 5
1 4 6
2 3 7
*/
