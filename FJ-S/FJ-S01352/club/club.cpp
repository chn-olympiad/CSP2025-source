#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],b[5],c[100005],m[5],x,d[100005],e[100005],f[100005],g[100005],md;
int bj(int i){
	if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
		return 0;
	}
	else if(a[i][1]>a[i][2]&&a[i][1]>a[i][0]){
		return 1;
	}
	return 2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int ii=0;ii<t;ii++){
		scanf("%d",&n);
		b[0]=b[1]=b[2]=m[0]=m[1]=m[2]=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			x=bj(i);
			b[x]+=a[i][x];
			c[i]=x;
			m[x]++;
		}
		for(int i=0;i<3;i++){
			if(m[i]>n/2){
				md=0;
				for(int j=0;j<n;j++){
					if(c[j]==i){
						d[md]=j;
						e[md]=a[j][i];
						md++;
					}
				}
				for(int j=0;j<md;j++){
					if(i==0){
						if(a[d[j]][1]>=a[d[j]][2]){
							f[j]=a[d[j]][0]-a[d[j]][1];
							g[j]=1;
						}
						else{
							f[j]=a[d[j]][0]-a[d[j]][2];
							g[j]=2;
						}
					}
					else if(i==1){
						if(a[d[j]][0]>=a[d[j]][2]){
							f[j]=a[d[j]][1]-a[d[j]][0];
							g[j]=0;
						}
						else{
							f[j]=a[d[j]][1]-a[d[j]][2];
							g[j]=2;
						}
					}
					else{
						if(a[d[j]][0]>=a[d[j]][1]){
							f[j]=a[d[j]][2]-a[d[j]][0];
							g[j]=0;
						}
						else{
							f[j]=a[d[j]][2]-a[d[j]][1];
							g[j]=1;
						}
					}
				}
				for(int j=0;j<md-1;j++){
					for(int k=j;k<md;k++){
						if(f[j]<f[k]){
							swap(f[j],f[k]);
							swap(d[j],d[k]);
							swap(g[j],g[k]);
							swap(e[j],e[k]);
						}
					}
				}
				while(md>n/2){
					b[i]-=e[md-1];
					m[i]--;
					b[g[md-1]]+=a[d[md-1]][g[md-1]];
					m[g[md-1]]++;
					md--;
				}
			}
		}
		printf("%d\n",b[0]+b[1]+b[2]);
	}
	return 0;
}