#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		int n;
		cin>>n;
		if(n==2){ //我连这5分都不一定能拿到 
			int a[2][3];
			cin>>a[0][0]>>a[0][1]>>a[0][2];
			cin>>a[1][0]>>a[1][1]>>a[1][2];
			int ans=0;
			for(int i=0;i<3;i++){
				int tmp=a[0][i];
				for(int j=0;j<3;j++){
					if(j==i) continue;
					ans=max(ans,tmp+a[1][j]);
				}
			}
		cout<<ans;
		}
		if(n==4){
			int a[n][3];
			for(int i=0;i<n;i++){
				cin>>a[i][0]>>a[i][1]>>a[i][2];
			}	
			
		}
	t--;
	}
	//我什么都不会. 
	return 0;
}
