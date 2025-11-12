#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=1e6;
int a[M][10],i1[N],i2[N],i3[N];
int n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int mxr=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			i1[i]=a[i][1];
		}
		for(int i=1;i<=n;i++){
			i2[i]=a[i][2];
		}
		for(int i=1;i<=n;i++){
			i3[i]=a[i][3];
		}
		sort(i1+1,i1+1+n);
		sort(i2+1,i2+1+n);
		sort(i3+1,i3+1+n);
		long long ans=0;
		for(int i=n;i>=n-mxr;i--){
            ans+=i1[i]+i2[i]+i3[i];
		}
		cout<<ans<<endl;
	}
    return 0;
}
