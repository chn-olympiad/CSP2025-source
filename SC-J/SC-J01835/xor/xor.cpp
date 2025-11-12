#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],id[500010],cnt,ans;
int f(int l,int r){
	if(l>=r)
		return 0;
	int u=0;
	for(int t=2;t<=r-l+1;t++){
		for(int i=l;i<=r-t+1;i++){
			int res=a[i];
			if(res==-1)
				continue;
			for(int j=i+1;j<=i+t-1;j++){
				if(a[j]==-1){
					res=-1;
					break;
				}
				res^=a[j];
			}
			if(res==k){
				u++;
				for(int o=i;o<=i+t-1;o++)
					a[o]=-1;
				i+=(i+t-2);
			}
		}
	}
	return u;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k)
			id[++cnt]=i;
	}
	ans=cnt;
	for(int i=1;i<=cnt;i++)
		ans+=f(id[i-1]+1,id[i]-1);
	printf("%lld",ans+f(id[cnt]+1,n));
	return 0;
}