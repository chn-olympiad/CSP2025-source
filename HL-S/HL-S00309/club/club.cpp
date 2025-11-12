#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int t,n,a[N],b[N],c[N],res[5],ans;

void dfs(int num,int tot){
	if(num>n){
		ans=max(ans,tot);
		return;
	}
	if(res[1]+1<=n/2){
		res[1]++;
		dfs(num+1,tot+a[num]);
		res[1]--;
	}
	if(res[2]+1<=n/2){
		res[2]++;
		dfs(num+1,tot+b[num]);
		res[2]--;
	}
	if(res[3]+1<=n/2){
		res[3]++;
		dfs(num+1,tot+c[num]);
		res[3]--;
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		bool flag=true;
		bool flag2=true;
		res[1]=res[2]=res[3]=0;
		ans=-0x3fffffff;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(!(b[i]==0&&c[i]==0)){
				flag=false;
			}
			if(!c[i]==0){
				flag2=false;
			}
		}
		if(flag==true){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=a[i];
			}
			printf("%lld\n",ans);
		}
		else{
			dfs(1,0);
			printf("%lld\n",ans);
		}
	}
	return 0;
}