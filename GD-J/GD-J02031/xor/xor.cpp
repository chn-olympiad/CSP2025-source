#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],pre[N],lst[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=a[i]^k;
		if(lst[x])ans=max(ans,pre[lst[x]]+1);
		if(a[i]==k)ans=max(ans,1);
		lst[a[i]]=i,pre[i]=max(pre[i-1],ans);
	}
	printf("%d",ans);
	return 0;
}
