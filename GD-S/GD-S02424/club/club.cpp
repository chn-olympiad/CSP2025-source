#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[10005][5];
		for(int i=1;i<=n;i++){
			int maxx=-1;
			int index=1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				// if(a[i][j]>maxx){
				// 	maxx=a[i][j];
				// 	index=j;
				// }
			}
			// a[i][4]=maxx;
			// a[i][5]=index;
		}
		// int cut[5]={0};
		// for(int i=1;i<=n;i++){
		// 	cut[a[i][5]]++;
		// }
		// for(int i=1;i<=3;i++){
		// 	if(cut[i]>n/2){

		// 	}
		// }
		if(n==2){
			int ans=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j){
						continue;
					}
					ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			cout<<ans;
			return 0;
		}
		
	}
	return 0;
}