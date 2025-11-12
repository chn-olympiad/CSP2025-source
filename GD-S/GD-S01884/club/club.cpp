#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,c[4];
ll a[100010][4],s,b[4][100010],d[200010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		memset(c,0,sizeof c);
		scanf("%d",&n);
		int f=0,ans=0;
		s=0;
		for(int i=1;i<=n;i++) {
			int ma=0,m=0;
			for(int j=1;j<=3;j++) {
				scanf("%lld",&a[i][j]);
				if(a[i][j]>ma) ma=a[i][j],m=j;
			}
			s+=a[i][m];
			b[m][++c[m]]=i;
			if(c[m]>n/2) f=m;
		}
		for(int i=1;i<=c[f];i++) {
			int v=b[f][i];
			ll mi=INT_MAX;
			for(int j=1;j<=3;j++) 
				if(j!=f) mi=min(mi,a[v][f]-a[v][j]);
			d[++ans]=mi;
		}
		sort(d+1,d+ans+1);
		for(int i=1;i<=max(0,c[f]-n/2);i++) {
			s-=d[i];
		}
		printf("%lld\n",s);
	}
	
	
	
	return 0;
} 
