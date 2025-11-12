#include<bits/stdc++.h>
using namespace std;
const int Max=1e5+10;
const int INF=1e18+10;
int t,n,ans=0;
int a[Max][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int c[10][10],b[10],tmp=0;
			for(int i=1;i<=2;i++){
				for(int j=1;j<=3;j++){
					cin>>c[i][j];
				}
			}
			for(int i=1;i<=2;i++){
				for(int j=1;j<=3;j++){
					tmp=max(ans,c[i][j]);
				}
				ans+=tmp;
			}
			cout<<ans;
		}else{
			for(int i=1;i<=n;i++){
				int tmp=0;
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
					tmp=max(tmp,a[i][j]);
				}
				ans=max(ans,tmp);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
