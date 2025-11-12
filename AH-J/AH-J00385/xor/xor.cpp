#include<bits/stdc++.h>
using namespace std;
int n,k,tp1,tp2,a[500005],zi[500005],m;
struct node1{
	int l,r,leth;
}ans[500005];
bool cmp(node1 x,node1 y){
	return x.leth<y.leth;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==0){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==0){
				tp2++;
			}
			if(a[i]==1&&a[i-1]==1){
				a[i]=0;
				tp1++;
			}
		}
		printf("%d",tp1+tp2);
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==1){
				tp1++;
			}
		}
		printf("%d",tp1);
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			zi[i]=zi[i-1]^a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((zi[j]^zi[i-1])==k){
					ans[++m].l=i;
					ans[m].r=j;
					ans[m].leth=j-i+1;
				}
			}
		}
		sort(ans+1,ans+m+1,cmp);
		int sum=0;
		for(int i=1;i<=m;i++){
			sum+=ans[i].leth;
			if(sum>n){
				printf("%d",i-1);
				return 0;
			}
		}
		printf("%d",m);
	}
	return 0;
}
