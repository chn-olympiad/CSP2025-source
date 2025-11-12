#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],b[1000005];
long long ans;
void dfs(int l,int aim,int s,int r){
	if(r==3&&l==3) return;
	if(aim<=0) return;
	for(int i =s;i<r;i++){
		aim-=a[i];
		if(aim>0){
			ans++;
			if(l>3)dfs(l-1,aim,i+1,r);
			else{
				return;
			}
		}else{
			return;
		}
		aim+=a[i];
	}
	if(r>3)dfs(r-1,b[r--]-a[r-1]*2,1,r-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i =1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	b[1]=a[1];
	for(int i =2;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=3;i<=n;i++){
		int maxx=a[i]*2;
		if(b[i]>maxx) ans++;
	}
	dfs(n,b[n]-a[n]*2,1,n);
	printf("%lld",ans%998244353);
	return 0;
}
