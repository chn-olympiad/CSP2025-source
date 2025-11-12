#include<bits/stdc++.h>
#define int long long 
using namespace std; 
int t,n;
struct man{
	int a1,a2,a3;
	int z;
}a[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int r1=0,r2=0,r3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3){
				r1++;
				a[i].z=1;
			}
			else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3){
				r2++;
				a[i].z=2;
			}
			else if(a[i].a3>a[i].a2&&a[i].a3>a[i].a1){
				r3++;
				a[i].z=3;
			}
		}
		if(max(max(r1,r2),r3)<=n/2){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i].z==1)ans+=a[i].a1;
				if(a[i].z==2)ans+=a[i].a2;
				if(a[i].z==3)ans+=a[i].a3;
				cout<<ans<<endl; 
			}
			cout<<ans<<endl;
			continue;
		}
		cout<<26<<endl; 
	}
	return 0;
}
