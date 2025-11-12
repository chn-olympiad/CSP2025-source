#include<bits/stdc++.h>
using namespace std;
int n,m,t,d[1000000][3],ai,bi,ci,p,k,l;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		p=n/2;
		m=ai=bi=ci=0;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&d[i][0],&d[i][1],&d[i][2]);
			if(ai<=p&&d[i][0]>=d[i][1]&&d[i][0]>=d[i][2]){
				m+=d[i][0];
				ai++;
			}
			else if(bi<=p&&d[i][1]>=d[i][2]){
				m+=d[i][1];
				bi++;
			}
			else{
				m+=d[i][2];
				ci++;
			}
		}
		printf("%d\n",m);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
