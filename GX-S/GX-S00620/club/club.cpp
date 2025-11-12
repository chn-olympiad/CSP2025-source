#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		while(n--){
			int a,b,c;
			cin>>a>>b>>c;
			ans+=max({a,b,c});
		}
		cout<<ans<<'\n';
	}
}
