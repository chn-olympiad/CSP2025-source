#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005],b[500005];
bool vis[500005];
int yh(int a,int b){
	bool x[25],y[25];
	int i=1,mx=0,sum=0,now=1;
	while(a>1){
		x[i]=a%2;
		a/=2;
		i++;
	}
	x[i]=a;
	mx=max(mx,i);
	i=1;
	while(b>1){
		y[i]=b%2;
		b/=2;
		i++;
	}
	y[i]=b;
	mx=max(mx,i);
	for(int i=1;i<=mx;i++){
		if(x[i]!=y[i]) sum+=now;
		now*=2;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n<=2){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==k) ans++;
		}
		if(yh(a[1],a[2])==k) ans++;
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			ans++;
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		int num=0;
		if(vis[i]) continue;
		for(int j=i;j<=n;j++){
			if(vis[j]) break;
			if(j==i){
				num=a[j];
			}else if(j>i){
				num=yh(num,a[j]);
			}
			if(num==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
