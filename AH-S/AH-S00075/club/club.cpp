#include<bits/stdc++.h>
using namespace std;
long long t,n,i,a[100009],b[100009],c[100009],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i],ans+=max(a[i],max(b[i],c[i]));
		cout<<ans<<endl;
	}
}
