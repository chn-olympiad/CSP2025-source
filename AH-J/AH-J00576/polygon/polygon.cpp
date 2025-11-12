#include <bits/stdc++.h>
using namespace std;
int n,k,a[5001],b[5001],c[5001];
long long ans;

int dfs(int j,int l,int n){
	long long sum=0;
	if(j+1==n){
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			x+=c[i],y=max(y,c[i]);
		}if(x>2*y){
			return 1;
		}
		return 0;
	}for(int i=l;i<=n;i++){
		c[i]=a[i];
		sum+=dfs(j+1,i+1,n),sum%=998244353;
	}return sum;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
    }for(int i=3;i<=n;i++){
		ans+=dfs(1,1,i);
	}printf("%lld",ans);
}
