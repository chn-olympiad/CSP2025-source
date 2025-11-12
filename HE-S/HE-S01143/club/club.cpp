#include<bits/stdc++.h>
using namespace std;
int n,t,l[100002],a,b;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>l[i]>>a>>b;
		}
		sort(l+1,l+1+n);
		for(int i = n;i>n/2;i--){
			ans+=l[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
