#include <bits/stdc++.h>
using namespace std;

struct k{
	int b[4];
}a[1000005];
int t;
bool f1=1,f2=1;
bool cmp1(k x,k y){
	return x.b[1]>y.b[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].b[1]>>a[j].b[2]>>a[j].b[3];
			if(a[j].b[2]!=0) f1=0;
			if(a[j].b[3]!=0){
				f1=0;
				f2=0;
			}
			
		}
		if(n==2){
			int ma=-1;
			for(int u=1;u<=3;u++){
				for(int w=1;w<=3;w++){
					if(w==u) continue;
					ma=max(ma,a[1].b[u]+a[2].b[w]);
				}
			}
			cout<<ma<<endl;
		}
		if(n!=2&&f1){
			int ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int u=1;u<=n/2;u++){
				ans+=a[u].b[1];
			}
			cout<<ans<<endl;
		}
		if(n!=2&&f2&&(!f1)){
			int ans=0,a1=0,a2=0;
			sort(a+1,a+n+1,cmp1);
			for(int u=1;u<=n;u++){
				if(a[u].b[1]>a[u].b[2]&&a1<n/2){
					ans+=a[u].b[1];
					a1++;
				}else if(a[u].b[1]>a[u].b[2]&&a1>=n/2){
					ans+=a[u].b[2];
					a2++;
				}else if(a[u].b[1]<a[u].b[2]&&a2<n/2){
					ans+=a[u].b[2];
					a2++;
				}else if(a[u].b[1]<a[u].b[2]&&a2>=n/2){
					ans+=a[u].b[1];
					a1++;
				}else if(a[u].b[1]==a[u].b[2]&&a1==a2){
					ans+=a[u].b[1];
					a1++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
