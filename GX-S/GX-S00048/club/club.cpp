#include<bits/stdc++.h>
using namespace std;
int t,n,a[200004],b[200006],c[200004];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		long long ans=0;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a+1,a+1+n);
		for(int j=n,k=1;k<=n/2;j--,k++){
			ans+=a[j];
		}
		cout<<ans<<endl;
	}


	return 0;
}
