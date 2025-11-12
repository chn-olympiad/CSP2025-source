#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,a[N][5],f[205][205][205],b[N];
pair<int,int> c[N];
bool cmp(pair<int,int> p,pair<int,int> q){
	return p.first+q.second>p.second+q.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool bl=true,bll=true;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0) bl=false;
			if(a[i][3]!=0) bl=bll=false;
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=max(0,i-j-n/2);k<=min(i-j,n/2);k++){
						f[i][j][k]=0;
						if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
						if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
						if(i-j-k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=n/2-i;j<=n/2;j++){
					ans=max(ans,f[n][i][j]);
				}
			}
			printf("%d\n",ans);
		}
		else if(bl){
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+1+n);
			int ans=0;
			for(int i=n;i>n/2;i--) ans+=b[i];
			printf("%d\n",ans);
		}
		else if(bll){
			for(int i=1;i<=n;i++) c[i]=make_pair(a[i][1],a[i][2]);
			sort(c+1,c+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n;i++){
				if(i<=n/2) ans+=c[i].first;
				else ans+=c[i].second; 
			}
			printf("%d\n",ans);
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++) ans+=max({a[i][1],a[i][2],a[i][3]});
			printf("%d\n",ans);
		}
	}
	return 0;
} 
