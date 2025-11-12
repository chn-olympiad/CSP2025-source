#include<bits/stdc++.h>
using namespace std;
int t;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		int n;
		long long ans=0;
		cin>>n;
		int a,b,c,s[100050];
	    for(int i=1;i<=n;i++){
	    	cin>>a>>b>>c;
	    	s[i]=a;
		}
		sort(s+1,s+n+1);
		for(int i=n;i>n/2;i--){
			ans+=s[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}