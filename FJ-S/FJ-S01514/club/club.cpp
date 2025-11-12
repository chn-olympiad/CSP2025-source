#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+5][4]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int R=n/2;
		if(n==2){
			int ans=-114514;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3&&j!=i;j++){
					ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			cout<<ans<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			cout<<ans<<endl;
		}	
	}
	return 0;
}
//LZQSMMNKDNDJTSQKDNDJZGLSPSZTTMDXCHBPXHXFZSBYQZHZYRWKDEX