#include<bits/stdc++.h>
using namespace std;
int t,x[100005],a[105][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n,sum=0;
		scanf("%d",&n);
		if(n==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
			}
			for(int i=1;i<=3;i++){
				int maxx=a[1][i];
				for(int j=1;j<=3;j++){
					if(i!=j){
						maxx+=a[2][j];
						sum=max(maxx,sum);
						maxx-=a[2][j];
					}
				}
			}
			printf("%d",sum);
			cout<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(j==1) scanf("%d",&x[i]);
					else scanf("%d",&x[0]);
				}
			}
			sort(x+1,x+1+n);
			for(int i=n;i>n/2;i--) sum+=x[i];
			printf("%d",sum);
			cout<<endl;
		}
	}
	return 0;
}
