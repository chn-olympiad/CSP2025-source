#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int t,n,ans;
int a1[N],a2[N],a3[N];
int c1,c2,c3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		c1=0,c2=0,c3=0,ans=0;
		int ed=(n-1)/2;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		sort(a1+1,a1+1+n);
		sort(a2+1,a2+1+n);
		sort(a3+1,a3+1+n);
		for(int i=1;i<=n;i++){
			if(ed-c1&&ed-c2&&ed-c3){
			    ans+=max(a1[i],max(a2[i],a3[i]));
			    if(a1-a2&&a1-a3) c1++;
			    else if(a2-a1&&a2-a3) c2++;
			    else c3++;
			}
			else if(ed-c2&&ed-c3){
			    ans+=max(a2[i],a3[i]);
			    if(a2-a3) c2++;
			    else c3++;
			   }
			else{
				ans+=max(a2[i],a1[i]);
				if(a2-a1) c2++;
				else c1++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
