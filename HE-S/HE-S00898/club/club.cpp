#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1000001][10],t,sum;
ll d[1000001][10],d2[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;
		memset(a,0,sizeof a);
		memset(d,0,sizeof d);
		memset(d2,0,sizeof d2);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			sum+=a[i][1];
		}
		for(int j=2;j<=3;j++){
			for(int i=1;i<=n;i++){
				d[i][j]=a[i][j]-a[i][1];
			}
		}
		for(int i=1;i<=n;i++){
			d2[i]=max(d[i][2],d[i][3]);
		}
		sort(d2+1,d2+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=d2[i];
		}
		printf("%d\n",sum);
	}


	return 0;
	fclose(stdin);
	fclose(stdout);
}

