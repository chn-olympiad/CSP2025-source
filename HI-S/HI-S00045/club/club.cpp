#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][8],cnt=0;
int x1[100005],x2[100005],x3[100005],sum[100005];
int maxx[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		cnt=0;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
			maxx[j]=max(max(a[j][1],a[j][2]),a[j][3]);
		}
		for(int j=1;j<=3;j++){
			for(int k=1;k<=n;k++){
				if(j==1){
					x1[k]=a[k][1];
				}else if(j==2){
					x2[k]=a[k][2];
				}else{
					x3[k]=a[k][3];
				}
			}
		}
		sort(x1+1,x1+n+1);
		sort(x2+1,x2+n+1);
		sort(x3+1,x3+n+1);
		int k=1;
		for(int j=n;j>=n-n/2+1;j--,k++){
			sum[k]=x1[j];
			k++;
			sum[k]=x2[j];
			k++;
			sum[k]=x3[j];
		}
		sort(sum+1,sum+k+1);
		for(int j=k;j>=k-n+1;j--){
			for(int p=1;p<=n;p++){
				if(maxx[p]==sum[j]){
					cnt+=sum[j];
					break;
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
