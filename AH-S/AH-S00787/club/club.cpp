#include<bits/stdc++.h>
using namespace std;
int ans,a[100009];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=n/2+1;i<=n;i++)
		ans+=a[i];
		cout<<ans<<'\n';
	}
	
	return 0;
}
