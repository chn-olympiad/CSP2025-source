#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int a[100000][2]={0};
		int b[100000]={0};
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>b[i];
			cin>>a[i][0];
			cin>>a[i][1];
		}
		sort(b,b+n);
		int ans=0;
		for(int i=n-1;i>=(n/2);i--){
			ans+=b[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
