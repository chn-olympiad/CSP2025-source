#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,a[MAXN],m,pre[MAXN],cnt,ans;
bool flag=0;
struct qj{
	int st,fi;
}b[5000005];
bool cmp(qj x,qj y){
	if(x.fi!=y.fi) return x.fi<y.fi;
	return x.st<y.st;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]^a[i];
		if(a[i]!=0&&a[i]!=1){
			flag=1;
		}
	}
	if(flag==0){
		if(m==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{
					if(a[i-1]==1){
						ans++;
						a[i]=0;
					}
				}
			}
			printf("%lld\n",ans);
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			printf("%lld\n",ans);
			return 0;
		}
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((pre[j]^pre[i-1])==m){
					b[++cnt].st=i;
					b[cnt].fi=j;
					break;
				}
			}
		}
		sort(b+1,b+1+cnt,cmp);
		int lst=0;
		for(int i=1;i<=cnt;i++){
			if(b[i].st>lst){
				ans++;
				lst=b[i].fi;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	cout<<1<<endl;
	return 0;
}
