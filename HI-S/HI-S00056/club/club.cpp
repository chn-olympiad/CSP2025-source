#include<bits/stdc++.h>
using namespace std;
int t,n,a[5][100005],c1,c2,c3,f1[100005],f2[100005],f3[100005],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=c1=c2=c3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){
				c1++;
				ans+=a[1][i];
				f1[c1]=a[1][i]-max(a[2][i],a[3][i]);
			}
			else if(a[2][i]>=a[3][i]){
				c2++;
				ans+=a[2][i];
				f2[c2]=a[2][i]-max(a[1][i],a[3][i]);
			}
			else{
				c3++;
				ans+=a[3][i];
				f3[c3]=a[3][i]-max(a[1][i],a[2][i]);
			}
		}
		if(c1>n/2){
			sort(f1+1,f1+c1+1);
			for(int i=n/2;i<c1;i++){
				ans-=f1[i-n/2+1];
			}
		}
		if(c2>n/2){
			sort(f2+1,f2+c2+1);
			for(int i=n/2;i<c2;i++){
				ans-=f2[i-n/2+1];
			}
		}
		if(c3>n/2){
			sort(f3+1,f3+c3+1);
			for(int i=n/2;i<c3;i++){
				ans-=f3[i-n/2+1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
