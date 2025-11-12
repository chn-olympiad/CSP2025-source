#include<bits/stdc++.h>
using namespace std;
int t,n,px;
struct nd{
	int z,id;
}a[111111][5];
struct q{
	int c,id;
}b[111111];

int cmp(nd x,nd y){
	return x.z>y.z;
}
int cmp2(q x,q y){
	return x.c>y.c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int f[3]={};
		long long dp[111111]={};
		scanf("%d",&n);
		px=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i][1].z);
			scanf("%d",&a[i][2].z);
			scanf("%d",&a[i][3].z);
			a[i][1].id=1;
			a[i][2].id=2;
			a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp);
			b[i].id=i;
			b[i].c=a[i][1].z-a[i][2].z;
		}
		sort(b+1,b+1+n,cmp2);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2;j++){
				int g=a[b[i].id][j].id;
				if(f[g]<n/2){
					dp[i]=dp[i-1]+a[b[i].id][j].z;
					f[g]++;
					break;
				}
			}
		}
		printf("%d\n",dp[n]);
	}
	
	return 0;
}
