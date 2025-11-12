#include<bits/stdc++.h>
using namespace std;
int a[7][10005];
int a1[7][10005],a2[7][20005],a3[7][10005];
int laji[10005],t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long c,yes,a2num,a1num,a3num,ans;
	scanf("%d",&t);
	for(int num=1;num<=t;num++){
		a1num=a3num=a2num=ans=yes=0;
		c=1;
		scanf("%d",&n);
		for(int qp=1;qp<=n;qp++){
			a[0][qp]=qp;
			scanf("%d%d%d",&a[1][qp],&a[2][qp],&a[3][qp]);
			if(a[1][qp]>=a[2][qp]&&a[1][qp]>=a[3][qp]){
				a[4][qp]=1;
				if(a[2][qp]>=a[3][qp]){
					a[5][qp]=2;
					a[6][qp]=3;
				}else if(a[3][qp]>a[3][qp]){
					a[5][qp]=3;
					a[6][qp]=2;
				}
			}else if(a[2][qp]>a[1][qp]&&a[2][qp]>=a[3][qp]){
				a[4][qp]=2;
				if(a[1][qp]>=a[3][qp]){
					a[5][qp]=1;
					a[6][qp]=3;
				}else if(a[3][qp]>a[1][qp]){
					a[5][qp]=3;
					a[6][qp]=1;
				}
			}else if(a[3][qp]>a[1][qp]&&a[3][qp]>a[2][qp]){
				a[4][qp]=3;
				if(a[1][qp]>=a[2][qp]){
					a[5][qp]=1;
					a[6][qp]=2;
				}else if(a[2][qp]>a[1][qp]){
					a[5][qp]=2;
					a[6][qp]=1;
				}
			}a1[0][qp]=a[0][qp];a1[1][qp]=a[1][qp];a1[2][qp]=a[2][qp];a1[3][qp]=a[3][qp];a1[4][qp]=a[4][qp];a1[5][qp]=a[5][qp];a1[6][qp]=a[6][qp];
			a2[0][qp]=a[0][qp];a2[1][qp]=a[1][qp];a2[2][qp]=a[2][qp];a2[3][qp]=a[3][qp];a2[4][qp]=a[4][qp];a2[5][qp]=a[5][qp];a2[6][qp]=a[6][qp];
			a3[0][qp]=a[0][qp];a3[1][qp]=a[1][qp];a3[2][qp]=a[2][qp];a3[3][qp]=a[3][qp];a3[4][qp]=a[4][qp];a3[5][qp]=a[5][qp];a3[6][qp]=a[6][qp];
		}for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				if(a1[1][j]>a1[1][j-1]){
					swap(a1[1][j],a1[1][j-1]);
					swap(a1[2][j],a1[2][j-1]);
					swap(a1[3][j],a1[3][j-1]);
					swap(a1[4][j],a1[4][j-1]);
				}if(a2[2][j]>a2[2][j-1]){
					swap(a2[1][j],a2[1][j-1]);
					swap(a2[2][j],a2[2][j-1]);
					swap(a2[3][j],a2[3][j-1]);
					swap(a2[4][j],a2[4][j-1]);
				}if(a3[3][j]>a3[3][j-1]){
					swap(a3[1][j],a3[1][j-1]);
					swap(a3[2][j],a3[2][j-1]);
					swap(a3[3][j],a3[3][j-1]);
					swap(a3[4][j],a3[4][j-1]);
				}
			}
		}for(int i=1;i<=n;i++){
			if(a1num==n/2)break;
			if(a1[4][i]==1){
				ans=ans+a1[1][i];
				laji[c]=a[0][i];
				c++;
			}
			a1num++;
		}for(int i=1;i<=n;i++){
			if(a2[4][i]==2){
				yes=0;
				if(a2num==n/2)break;
				for(int wy=1;wy<=c;wy++){
					if(a2[0][wy]==0)yes=1;
					if(yes==1)break;
				}if(yes==1)break;
				ans=ans+a2[2][i];
				a2num++;
				laji[c]=a2[0][i];
				c++;
			}
		}for(int i=1;i<=n;i++){
			if(a3num==n/2)break;
			if(a3[4][i]==3){
				yes=0;
				for(int wy1=1;wy1<=c;wy1++){
					if(a3[0][wy1]==0)yes=1;
					if(yes==1)break;
				}if(yes==1)break;
				ans=ans+a3[3][i];
			}a3num++;
		}cout<<ans<<"\n";
	}return 0;
}
