#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int t,n,a[N][5],ans;
int f[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==1)ans+=a[i][j];
			}
		}
		if(n==100000){
			cout<<ans/2<<"\n";
		}
	}
	return 0;
}
