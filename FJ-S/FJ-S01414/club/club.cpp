#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,a[N][3],b[N],c[N],cnt[3],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cnt[0]=cnt[1]=cnt[2]=m=ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			int v=-1;
			for(int j=0;j<3;++j){
				scanf("%d",&a[i][j]);
				if(a[i][j]>v)v=a[i][j],c[i]=j;
			}
			cnt[c[i]]++,ans+=v;
		}
		int p=-1;
		for(int i=0;i<3;++i)
			if(cnt[i]>n/2){
				p=i;
				break;
			}
		if(~p){
			for(int i=1;i<=n;++i)
				if(c[i]==p){
					b[++m]=INT_MAX;
					for(int j=0;j<3;++j)
						if(j!=p)b[m]=min(b[m],a[i][p]-a[i][j]);
				}
			sort(b+1,b+m+1);
			for(int i=1;i<=cnt[p]-n/2;++i)ans-=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
CSP 2025 RP++!
*/
