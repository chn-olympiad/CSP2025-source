#include <bits/stdc++.h>
using namespace std;
int n,k,sum,ans,b,f;
int a[500005];
int qzyh[500005];
struct node{
	int u,v;
}s[1000005];
bool cmp(node x,node y){
	return x.u<y.u;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1) f=1;
		qzyh[i]=qzyh[i-1]^a[i];
	}
	if(f==1){
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if((qzyh[r]^qzyh[l-1])==k){ 
					s[++sum].u=l;
					s[sum].v=r;
					break;
				}
			}
		}
		sort(s+1,s+sum+1,cmp);
		for(int i=1;i<=sum;i++){
			for(int j=i+1;j<=sum;j++){
				if(s[i].u<s[j].u && s[i].v>s[j].v){
					s[i].u=-1,s[i].v=-1;
				}
			}
		}
		for(int i=1;i<=sum;i++){
			if(s[i].u==-1 && s[i].v==-1) continue;
			if(s[i].u>b){
				ans++;
				b=s[i].v;
			}
		}
		printf("%d",ans);
	}else{
		if(k==1){
			for(int i=1;i<=n;i++){
				ans+=a[i];
			}
			printf("%d",ans);
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			for(int i=1;i<=n;i++){
				if(a[i]==1 && a[i+1]==1) ans++,i++;
			}
			printf("%d",ans);
		}
	}
	return 0;
}
