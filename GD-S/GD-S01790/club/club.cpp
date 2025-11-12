#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int _;
int n;
int a[N][4];
int fi[N],se[N],c[N],m;
int cnt[4];
int ans;
void Solve(){
	scanf("%d",&n); cnt[1]=cnt[2]=cnt[3]=0; ans=0;
	for(int i=1;i<=n;i++) 
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	for(int i=1;i<=n;i++){
		ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]) fi[i]=1,se[i]=2;
		if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]) fi[i]=1,se[i]=3;
		if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]) fi[i]=2,se[i]=1;
		if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]) fi[i]=2,se[i]=3;
		if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]) fi[i]=3,se[i]=1;
		if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]) fi[i]=3,se[i]=2;
		++cnt[fi[i]]; 
	} m=0;
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
		int sum=max(cnt[1],max(cnt[2],cnt[3]));
		for(int i=1;i<=n;i++)
			if(cnt[fi[i]]>n/2) c[++m]=a[i][fi[i]]-a[i][se[i]];
		sort(c+1,c+m+1);
		for(int i=1;i<=sum-n/2;i++) ans-=c[i];
	} printf("%d\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&_);
	while(_--) Solve();
	return 0;
} 
