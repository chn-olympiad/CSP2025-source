#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int b[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
//		for(int i=1;i<=n;i++){
//			cin>>a[i].a>>a[i].b>>a[i].c;
//		}
		if(n==2){
			int maxn=0;
			cin>>a[1][1]>>a[1][2]>>a[1][3]>>a[2][1]>>a[2][2]>>a[2][3];
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(j!=k){
						maxn=max(maxn,a[1][j]+a[2][k]);
					}
				}
			}
			cout<<maxn<<"\n";
		}
		else{
			int x,y;
			for(int i=1;i<=n;i++){
				cin>>b[i]>>x>>y;
			}
			sort(b+1,b+n+1);
			int ans=0;
			for(int i=n;i>=n/2;i++){
				ans+=b[i];
			}
			cout<<ans<<"\n";
		}
		
	}
}
