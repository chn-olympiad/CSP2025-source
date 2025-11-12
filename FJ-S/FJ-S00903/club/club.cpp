#include<bits/stdc++.h>
using namespace std;
long long c,t,n,p1[100001],p2[100001],p3[100001],ans[10],mx[2][100001],mn[2][100001],mi[2][100001],b[3],mcn[2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	mcn[1] = 0x43;
	scanf("%lld",t);
	for(int a = 1;a <= t;a++){
		scanf("%lld",n);
		for(int i = 1;i <= n;i++){
			scanf("%lld%lld%lld",p1[i],p2[i],p3[i]);
			if(p1[i]>p2[i]){
				if(p1[i]>p3[i]){
					mx[1][i]=p1[i];
					mx[2][i]=1;
					if(p2[i]>p3[i]){
						mn[1][i]=p3[i];
						mn[2][i]=3;
					}
					else{
						mn[1][i]=p2[i];
						mn[2][i]=2;
					}
				}
				else{
					mx[1][i]=p3[i];
					mx[2][i]=3;
					mn[1][i]=p2[i];
					mn[2][i]=2;
				}
			} 
			else{
				if(p2[i]>p3[i]){
					mx[1][i]=p2[i];
					mx[2][i]=2;
					if(p1[i]>p3[i]){
						mn[1][i]=p3[i];
						mn[2][i]=3;
					}
					else{
						mn[1][i]=p1[i];
						mn[2][i]=1;
					}
				}
				else{
					mx[1][i]=p3[i];
					mx[2][i]=3;
					mn[1][i]=p1[i];
					mn[2][i]=1;
				}
			}
			mi[1][i] = p1[i]+p2[i]+p3[i]-mx[1][i]-mn[1][i];
			mi[2][i] = 6-mx[2][i]-mn[2][i];
		}
		for(int i = 1;i <= n;i++){
			if(b[mx[2][i]] <= n/2){
				ans[a] += p1[i];
				if(mcn[1] > mx[1][i]-mi[1][i]){
					c = mcn[1];
					mcn[1] = mx[1][i]-mi[1][i];
					mcn[2] = i;
				}
				b[mx[2][i]]++;
			}
			else{
				mcn[1] = min(mcn[1],mx[1][i]-mi[1][i]);
				ans[a] -= mcn[1];
				b[mi[2][mcn[2]]]++;
				mcn[1] = c;
			}
		}
	}
	for(int a = 1;a <= t;a++){
		printf("%lld\n",ans[a]);
	}
	return 0;
}
