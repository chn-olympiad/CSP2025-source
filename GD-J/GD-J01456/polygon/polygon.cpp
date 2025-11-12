#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int N=5005,P=998244353;
int n,a[N];
ll ans=0;

void dfs(int x){
	for(int i=0;i<(1<<(n-x));++i){
		int tmp=0;
		for(int j=x+1;j<=n;++j){
			if(i&(1<<(j-x-1))){
				tmp+=a[j];
			}
		}
		ans+=tmp>a[x];
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	if(n>=27){
		ll f[N];
		f[0]=1;
		for(int i=1;i<=n;++i){
			f[i]=(1ll*i*f[i-1])%P;
		}
		for(int i=3;i<=n;++i){
			ans=(ans+f[n]/((f[i]*f[n-i])%P))%P;
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n-2;++i){
		dfs(i);
		ans=ans%P;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

