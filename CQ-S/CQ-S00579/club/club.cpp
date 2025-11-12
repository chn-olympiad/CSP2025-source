#include<bits/stdc++.h>
using namespace std;
int a[100005][3],sl[3],bm1[100005],bm2[100005],bm3[100005],ans[5];
int main(){
	int t,n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		sl[0]=0;
		sl[1]=0;
		sl[2]=0;
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d%d%d",&a[j][0],&a[j][1],&a[j][2]);
			if(a[j][0]>=a[j][1]&&a[j][0]>=a[j][2]){
				ans[i]+=a[j][0];
				bm1[sl[0]]=a[j][0]-max(a[j][1],a[j][2]);
				sl[0]++;
			}else if(a[j][1]>=a[j][0]&&a[j][1]>=a[j][2]){
				ans[i]+=a[j][1];
				bm2[sl[1]]=a[j][1]-max(a[j][0],a[j][2]);
				sl[1]++;
			}else{
				ans[i]+=a[j][2];
				bm3[sl[2]]=a[j][2]-max(a[j][0],a[j][1]);
				sl[2]++;
			}
		}
		if(sl[0]>n/2){
			sort(bm1,bm1+sl[0]);
			for(int j=0;j<sl[0]-n/2;j++)
				ans[i]-=bm1[j];
		}else if(sl[1]>n/2){
			sort(bm2,bm2+sl[1]);
			for(int j=0;j<sl[1]-n/2;j++)
				ans[i]-=bm2[j];
		}
		else if(sl[2]>n/2){
			sort(bm3,bm3+sl[2]);
			for(int j=0;j<sl[2]-n/2;j++)
				ans[i]-=bm3[j];
		}
	}
	for(int i=0;i<t;i++)
		printf("%d\n",ans[i]);
	return 0;
}
