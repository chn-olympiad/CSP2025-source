#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int as[100005],bs=0,bd=0,bz=0;
		for(int i=1;i<=n;i++){
			as[i]=-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]>as[i]){
					as[i]=a[i][j];
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(a[i][j]==as[i]){
						if(j==1){
							bs++;
						}
						if(j==2){
							bd++;
						}
						if(j==3){
							bz++;
						}
					}
				}
			}
			int ad[100005];
			for(int i=1;i<=n;i++){
				ad[i]=-1;
			}
			for(int i=1;i<=n;i++){
				if(bs>n/2||bd>n/2||bz>n/2){
					for(int i=1;i<=n;i++){
						for(int j=1;j<=3;j++){
							if(a[i][j]==as[i]){
								a[i][j]=0;
							}
							else{
								if(a[i][j]>ad[i]){
								   ad[i]=a[i][j];	
								}
							}
						}
					}
					int ans[100005];
					for(int i=1;i<=n;i++){
						ans[i]=as[i]-ad[i];
					}
					for(int i=1;i<=n;i++){
						if(ans[i]<ans[i+1]){
							as[i]=ans[i];
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<as[i];
		}
	}
	return 0;
}
