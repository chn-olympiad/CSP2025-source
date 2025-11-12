#include<bits/stdc++.h>
#define N 100001
#define f(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int t,n,a[N][4],s[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		f(i,1,n)f(j,1,3)scanf("%d",&a[i][j]);
		f(i,1,n)s[i]=a[i][1];
		sort(s+1,s+n+1);
		int ans=0;
		for(int i=n;i>(n>>1);i--)ans+=s[i];
		printf("%d",ans);
	}
	return 0;
}
