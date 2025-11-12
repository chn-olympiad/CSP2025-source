#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,x,y,res,ans,cnt[3],id[N],a[N][3],b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
		ans=res=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			x=y=-1;
			for(int j=0;j<3;j++) if(a[i][j]>x&&cnt[j]<n/2){
				x=a[i][j];
				y=j;
			}
			res+=x;
			cnt[y]++;
		}
		ans=max(ans,res);
		for(int p=0;p<3;p++){
			res=0;
			for(int i=1;i<=n;i++){
				x=0;
				for(int j=0;j<3;j++) if(p!=j) x=max(x,a[i][j]);
				res+=x;
				b[i]=a[i][p]-x;
			}
			sort(b+1,b+n+1,greater<int>());
			for(int i=1;i<=n/2;i++) res+=b[i];
			ans=max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
