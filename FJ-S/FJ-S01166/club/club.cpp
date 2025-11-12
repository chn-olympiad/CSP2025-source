#include<bits/stdc++.h>
#define maxn 100010
#define maxm 2010
using namespace std;
int a[maxn][5];
int T,n,ans;
struct club{
	int a[maxn],b[maxn],c[maxn];
}s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int f[maxm][maxm]={0};
		ans=0;
		scanf("%d",&n);
		int m=n/2,l=1;
		bool flag1=false,flag2=false;
		for(int i=1;i<=n;++i){
			cin>>s.a[i]>>s.b[i]>>s.c[i];
			if(!s.b[i] && !s.c[i]) flag1=true;
			if(!s.c[i]) flag2=true;
		}
		sort(s.a+1,s.a+n+1);
		if(flag1){
			for(int i=n;i>m;--i) ans+=s.a[i];
			cout<<ans<<endl;
			continue;
		}
		if(flag2){}
		for(int i=1;i<=m;++i)
			for(int j=1;j<=m;++j){
				if(n-i-j>m) continue;
				f[i][j]=max(f[i-1][j]+s.a[l],f[i][j-1]+s.b[l]);
				f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1])+s.c[l]);
				ans=max(ans,f[i][j]);
				++l;
			}
		l=1;
		sort(s.b+1,s.b+n+1);
		for(int i=1;i<=m;++i)
			for(int j=1;j<=m;++j){
				if(n-i-j>m) continue;
				f[i][j]=max(f[i-1][j]+s.a[l],f[i][j-1]+s.b[l]);
				f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1])+s.c[l]);
				ans=max(ans,f[i][j]);
				++l;
			}
		l=1;
		sort(s.c+1,s.c+n+1);
		for(int i=1;i<=m;++i)
			for(int j=1;j<=m;++j){
				if(n-i-j>m) continue;
				f[i][j]=max(f[i-1][j]+s.a[l],f[i][j-1]+s.b[l]);
				f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1])+s.c[l]);
				ans=max(ans,f[i][j]);
				++l;
			}
		printf("%d\n",ans);
	}
	return 0;
}
