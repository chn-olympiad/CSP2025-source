#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int a[100010][3];
int g[4];
ll f[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	for(int q=1;q<=T;q++){
		cin>>n;
		int maxn=n/2;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		if(n==2){
			ll ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j) continue;
					if(a[1][i]+a[2][j]>ans){
						ans=a[1][i]+a[2][j];
					}
				}
			}
			printf("%lld\n",ans);
		}
		else{
			for(int i=n;i>1;i--){
				for(int j=1;j<i;j++){
					if(a[j][1]<a[j+1][1]){
						swap(a[j],a[j+1]);
					}
				}
			}
			ll ans=0;
			for(int i=1;i<=maxn;i++){
				ans+=a[i][1];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}