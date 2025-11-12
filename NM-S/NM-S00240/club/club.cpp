#include<bits/stdc++.h>
using namespace std;
long long n,rs,a,b,c,ans;
int main(){
 	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>rs;
		for(int j=0;j<rs;j++){
			cin>>a>>b>>c;
			ans+=max(max(a,c),b);
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
