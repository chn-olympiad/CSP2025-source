#include<bits/stdc++.h>
using namespace std;
int t,a[100005][100005]={0};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		int x=n/2;
		while(x--){
			for(int i=0;i<3;i++){
				int ma=-1;
				for(int j=0;j<n;j++){
					ma=max(a[j][i],ma);
				}
				ans+=ma;
				for(int j=0;j<n;j++){
					if(ma==a[j][i]){
						a[j][i]=0;
						break;
					} 
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
