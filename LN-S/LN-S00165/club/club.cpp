#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],b[100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(j==0){
					b[i]=a[i][j];
				}
			}
		}
		sort(b,b+n);
		for(int i=n-1;i>=n/2;i--){
			ans+=b[i];
		}
		cout<<ans;
	}
	return 0;
}
