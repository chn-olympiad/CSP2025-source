#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5]	;
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ans+=max({a[i][1],a[i][2],a[i][3]});
		}
		cout<<ans;
	}
} 