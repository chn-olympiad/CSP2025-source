#include<bits/stdc++.h>
using namespace std;
int t,n,a[10001][3],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int r=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans;
	}
	return 0;
}
