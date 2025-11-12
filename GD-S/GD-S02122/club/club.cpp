#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans;
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	fclose(stdin);
	fclose(stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j)ans=max(a[1][i]+a[2][j],ans);
				}
			}
		}
		if(n==4){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int x=1;x<=3;x++){
						for(int y=1;y<=3;y++){
							if(i==j==x||i==j==y||j==x==y||i==x==y) ans=ans;
							else ans=max(a[1][i]+a[2][j]+a[3][x]+a[4][y],ans);
						}
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
