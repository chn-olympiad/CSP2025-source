#include<bits/stdc++.h>

using namespace std;

const int N=1e+5;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a,b,c;
			for(int j=1;j<=n;j++){
			if(a>=b&&a>=c){
				ans=ans+a;
			}
			else if(b>=a&&b>=c){
				ans=ans+b;
			}
			else if(c>=a&&c>=b){
				ans=ans+c;
			}
		}
	}
	cout<<ans<<'/n';
	ans=0;
}
	return 0;
}
