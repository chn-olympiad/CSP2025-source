#include<bits/stdc++.h>
using namespace std;
int t,n,r[4],m;
int c[100010][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		memset(c,0,sizeof(c));
		memset(r,0,sizeof(r));
		m=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&c[i][1],&c[i][2],&c[i][3]);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(max(c[i][1],max(c[i][2],c[i][3]))<max(c[j][1],max(c[j][2],c[j][3]))){
					swap(c[i],c[j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			int id=0,ans=-1;
			for(int j=1;j<=3;j++){
				if(c[i][j]>ans&&r[j]<n/2) {
					ans=c[i][j];
					id=j;
				}
			}
			r[id]++;
			m+=ans;
		}
		printf("%d\n",m);
	}
}
