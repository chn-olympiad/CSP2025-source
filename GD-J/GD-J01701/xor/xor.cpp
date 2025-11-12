#include<bits/stdc++.h>
#define int long long
#define lc u<<1
#define rc u<<1|1
using namespace std;
int n,k;
const int N=5e5+10;
int a[N];
int ans;
bool vis[N];
bool query(int l,int r){
	for(int i=l;i<=r;i++){
		if(vis[i]) return false;
	}
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum=sum^a[i];
	}
	if(sum==k){
		for(int i=l;i<=r;i++){
			vis[i]=true;
		}
		return true;
	}
	return false;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int num=1;num<=n;num++){
		for(int l=1,r=num;r<=n;l++,r++){
			if(query(l,r)){
				ans++;
			}
		}
	}
	printf("%lld",ans);
}
