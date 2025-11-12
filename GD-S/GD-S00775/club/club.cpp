#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],s[5],maxx1[100005],maxx2[100005],tmp[100005],k,tt,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s[1]=s[2]=s[3]=0;
		k=0;
		ans=0; 
		for(int i=1;i<=n;i++){
			maxx1[i]=0; maxx2[i]=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>=maxx1[i]){
					maxx2[i]=maxx1[i];
					maxx1[i]=a[i][j];
				}
				else if(a[i][j]>maxx2[i]){
					maxx2[i]=a[i][j];
				}
			}
			for(int j=1;j<=3;j++){
				if(a[i][j]==maxx1[i]){
					s[j]++;
					break;
				}
			}
			ans+=maxx1[i];
		}
		if(s[1]>=s[2]&&s[1]>=s[3])tt=1;
		if(s[2]>=s[1]&&s[2]>=s[3])tt=2;
		if(s[3]>=s[1]&&s[3]>=s[2])tt=3;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]==maxx1[i]){
					if(j==tt){
						tmp[++k]=maxx1[i]-maxx2[i];
					}
					break;
				}
			}
		}
		sort(tmp+1,tmp+1+k);
		for(int i=1;i<=k-n/2;i++){
			ans-=tmp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
