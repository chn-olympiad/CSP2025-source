#include <bits/stdc++.h>
using namespace std;
long long t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long a=0,ans=0,x=n;
		while(x--){
			int ai,bi,ci;
			cin>>ai>>bi>>ci;
			if(a<=n/2){
				ans+=ai;
				a++;
			}
		}
		cout<<ans<<endl;
		ans=a=0;
	}
	return 0;
}
