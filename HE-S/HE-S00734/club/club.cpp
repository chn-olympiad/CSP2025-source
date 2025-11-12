#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int ans,t,f,n,v;
int a[MAXN][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	v=0;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				v=max(v,a[i][j]);
			}
			ans+=v;
		}
		cout<<ans;
	}
	
	
	return 0;
}
