#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N],b[N],c[N],x,y,z,l1,l2,l3,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		l1=l2=l3=ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z){
				a[++l1]=min(x-y,x-z);
				ans+=x;
			}
			else if(y>=x&&y>=z){
				b[++l2]=min(y-x,y-z);
				ans+=y;
			}
			else if(z>=x&&z>=y){
				c[++l3]=min(z-x,z-y);
				ans+=z;
			}
		}
		int k=n/2;
		if(l1<=k&&l2<=k&&l3<=k){
			printf("%d\n",ans);
			continue;
		}
		if(l1>k){
			sort(a+1,a+l1+1);
			for(int i=1;i<=l1-k;i++){
				ans-=a[i];
			}
		}
		else if(l2>k){
			sort(b+1,b+l2+1);
			for(int i=1;i<=l2-k;i++){
				ans-=b[i];
			}
		}
		else{
			sort(c+1,c+l3+1);
			for(int i=1;i<=l3-k;i++){
				ans-=c[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}