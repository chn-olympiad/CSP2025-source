#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,m,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		int a[N][4]={0};
		int ans[N],o=1;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<n;i++){
			ans[o]=a[i][1]+a[i+1][2];
			o++;
			ans[o]=a[i][1]+a[i+1][3];
			o++;
			ans[o]=a[i][2]+a[i+1][1];
			o++;
			ans[o]=a[i][2]+a[i+1][3];
			o++;
			ans[o]=a[i][3]+a[i+1][1];
			o++;
			ans[o]=a[i][3]+a[i+1][2];
			o++;
		}
		sort(ans+1,ans+o);
		cout<<ans[o-1];
	}
	return 0;
}
	
