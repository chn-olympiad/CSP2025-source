#include<bits/stdc++.h>
using namespace std;
int n,k,tot=0,ans=0,a[500005],Left[500005],vis[500005];
long long sum[500005];
struct len{
	int l,r;
}b[500005];
bool A=1,B=1;
bool cmp(len x,len y){
	return x.r-x.l<y.r-y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=a[i]^sum[i-1];
		if(sum[i]==k){
			if(!Left[1]) b[++tot].l=1,b[tot].r=i,Left[1]=tot;
			else b[Left[1]].r=min(b[Left[1]].r,i);
		}
		if(a[i]!=1) A=0;
		if(a[i]>1) B=0;
	}
	if(A&&k==0){
		cout<<n/2;
		return 0; 
	}
	if(B&&k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{
					if(a[i+1]==1) i++,ans++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				if(!Left[j]) b[++tot].l=j,b[tot].r=i,Left[j]=tot;
				else b[Left[j]].r=min(b[Left[j]].r,i);
			}
		}
	}
	sort(b+1,b+1+tot,cmp);
	//for(int i=1;i<=tot;i++) cout<<b[i].l<<" "<<b[i].r<<endl;
	for(int i=1;i<=tot;i++){
		bool flag=0;
		for(int j=b[i].l;j<=b[i].r;j++){
			if(vis[j]){
				flag=1;
				break;
			}
		}
		if(!flag){
			ans++;
			for(int j=b[i].l;j<=b[i].r;j++) vis[j]=1;
		}
	}
	printf("%d",ans);
	return 0;
}
