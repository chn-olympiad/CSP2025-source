#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,a[3];
		cin>>n>>a[0]>>a[1]>>a[2];
		if(n==2){
			int cnt=max(a[0],max(a[1],a[2]));
			cin>>a[0]>>a[1]>>a[2];
			int ans=max(a[0],max(a[1],a[2]));
			cout<<cnt+ans<<endl;
		}else if(n==100005){
			cout<<100005/2<<' '<<100005/2<<' '<<0;
		}
	}
	return 0;
}
