#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005][25],mb[25];
int s[25],d,c;
int vis[1050000];
struct data1{
	int l;
	int r;
}f[500005];
int nn=0;
bool cmp(data1 x,data1 y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	int xb=22,x=(1<<22),w=m;
	while(w){
		if(w>=x){
			w-=x;
			mb[xb]++;
		}
		xb--;
		x=(x>>1);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		xb=22,x=(1<<22),w=c;
		while(w){
			if(w>=x){
				w-=x;
				a[i][xb]++;
			}
			xb--;
			x=(x>>1);
		}
	}
	vis[0]=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		x=1;
		sum=0;
		d=0;
		for(int j=0;j<=22;j++){
			if(s[j]==a[i][j])s[j]=0;
			else s[j]=1;
			d+=x*s[j];
			if(mb[j]!=s[j])sum+=x;
			x*=2;
		}
		if(vis[sum]!=0||sum==0){
			f[++nn].l=vis[sum]+1;
			f[nn].r=i;
		}
		vis[d]=i;
	}
	int mo=0,ans=0;
	sort(f+1,f+1+nn,cmp);
	for(int i=1;i<=nn;i++){
		if(mo<f[i].l){
			mo=f[i].r;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}/*
*/
