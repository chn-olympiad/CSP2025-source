#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans=0;
		cin>>n;
			for(int j=1;j<=n;j++){
				cin>>a[j]>>b[j]>>c[j];
			}
			sort(a+1,a+n+1);
			for(int j=n;j>n/2;j--)ans+=a[j];
			cout<<ans<<endl;
		}
	}
	return 0;
}
