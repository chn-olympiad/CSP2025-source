#include<bits/stdc++.h>
using namespace std;
int n,t,c[4],e[100005][4],mymax,maxj,maxi,ans,total=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[1][i],&e[2][i],&e[3][i]);
		}
		while(total!=n){
			mymax=0;
			for(int i=1;i<=4;i++){
				for(int j=1;j<=n;j++){
					mymax=max(mymax,e[i][j]);
					if(mymax=e[i][j])maxj=j,maxi=i;
				}
			}
			if(c[maxi]<=n/2){
				c[maxi]++;
				ans+=mymax;
				e[1][maxj]=-1,e[2][maxj]=-1,e[3][maxj]=-1;
				total++;
			}else{
				for(int i=1;i<=n;i++)e[maxi][i]=-1;
			}
		}
		printf("%d",ans);
		ans=0,total=0,maxi=0,maxj=0;
		memset(e,0,sizeof(e));
		memset(c,0,sizeof(c));
	}
	return 0;
}
