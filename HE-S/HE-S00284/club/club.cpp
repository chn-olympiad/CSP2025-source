#include <bits/stdc++.h>
using namespace std;
int n,a[100001][5];
long long ans;
int sum[5];
inline void dfs (int i,long long num){
	if (i==n+1){
		ans = max(ans,num);
	    return;
    }
    for (int j=1;j<=3;j++)
        if (sum[j]<n/2){
        	sum[j]++;
        	dfs (i+1,num+a[i][j]);
        	sum[j]--;
		}
}
inline void sovle(){
	memset(sum,0,sizeof(sum));
	ans = 0;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	    scanf ("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	dfs (1,0);
	printf("%lld",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int test;
	scanf ("%d",&test);
	for(;test--;)
	    sovle();
} 
