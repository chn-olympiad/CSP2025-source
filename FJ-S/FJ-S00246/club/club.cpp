#include<bits/stdc++.h>
using namespace std;
int t,n=100005,ans=0;
int a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1]>>a[2]>>a[3];
			if(a[1]>a[2] && a[1]>a[3]){
				ans+=a[1];	
			}
			if(a[2]>a[1] && a[2]>a[3]){
				ans+=a[2];
			
			}
			if(a[3]>a[1] && a[3]>a[2]){
				ans+=a[i,3];
			}
}
cout<<ans<<endl;
ans=0;
}
	return 0;
}
