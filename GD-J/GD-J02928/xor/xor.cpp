#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[500010];
int sum[500010];
bool cmp(node X,node Y){
	return X.x>Y.x||(X.x==Y.x&&X.y<Y.y);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,ans=0,pre=1000000000;
	scanf("%d%d",&n,&k);
	if(k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				int tmp;
				scanf("%d",&tmp);
				if(tmp==0)
					ans++,pre=0;
				else{
					if(pre==1){
						ans++;
						pre=0;
					}
					else
						pre=1;
				}
			}
			printf("%d",ans);
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				int tmp;
				scanf("%d",&tmp);
				if(tmp==1){
					if(pre==1){
						ans++;
						pre=0;
					}
					else
						pre=1;
				}
				else
					pre=0;
			}
			printf("%d",ans);
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		sum[i]=(sum[i-1]^tmp);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((sum[i-1]^sum[j])==k){
				a[++cnt].x=i;
				a[cnt].y=j;
			}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		if(pre>a[i].y){
			ans++;
			pre=a[i].x;
		}
	printf("%d",ans);
	return 0;
}

