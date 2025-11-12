#include<bits/stdc++.h>
using namespace std;
int t,n,a[5][100005],b[100005],c[100005];
long long ans,sum;
bool f=1,l=1;
void dfs(int x,int q,int w,int e){
	if(q>n/2||w>n/2||e>n/2){
		return ;
	}
	if(x==n+1){
		for(int i=1;i<=n;i++){
			ans+=a[b[i]][i];
			
		}
		sum=max(sum,ans);
		ans=0;
		return ;
	}
	b[x]=1;
	dfs(x+1,q+1,w,e);
	b[x]=2;
	dfs(x+1,q,w+1,e);
	b[x]=3;
	dfs(x+1,q,w,e+1);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			if(a[2][i]!=0||a[3][i]!=0){
				f=0;
			}
			if(a[3][i]!=0){
				l=0;
			}
		}
		if(f){
			sort(a[1]+1,a[1]+1+n);
			for(int i=n/2+1;i<=n;i++){
				sum+=a[1][i];
			}
			printf("%lld\n",sum);
			return 0;
		}
		if(l){
			for(int i=1;i<=n;i++){
				sum+=a[1][i];
				c[i]=a[1][i]-a[2][i];
			}
			sort(c+1,c+n+1);
			for(int i=1;i<=n/2;i++){
				sum-=c[i];
			}
			cout<<sum;
			return 0;
		}
		dfs(1,0,0,0);
		printf("%lld\n",sum);
	}
	return 0;
}  
