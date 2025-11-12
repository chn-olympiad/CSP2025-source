#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool ka=1;
		int n,a[N],b[N],c[N],d[N];
		cin>>n;
		if(n==2){
			long long maxx=0;
			ka = 0;
			for(int i=1;i<=3;i++){
				cin>>a[i];
			}
			for(int i=1;i<=3;i++){
				cin>>b[i];
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						long long x=0;
						x=a[i]+b[j];
						maxx = max(maxx,x);
					}
				}
			}
			cout<<maxx<<endl;
			continue;
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
				if(c[i]!=0||b[i]!=0){
					ka=0;
				}
			}
		}
		if(ka==1){
			long long ans=0,sum=0;
			sort(a+1,a+n+1);
			for(int i=1;i<=n;i++){
				sum+=a[i];
			}
			for(int i=1;i<=n/2;i++){
				ans += a[i];
			}
			cout<<sum-ans<<endl;
			continue;
		}
	}
	return 0;
} 
