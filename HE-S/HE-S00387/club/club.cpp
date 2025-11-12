#include <bits/stdc++.h>
using namespace std;
int d[100010];
int a[100010][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,a1=0,b1=0,c1=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
				a1++;
				d[i]=a[i][1];
			}
			else if(a[i][2]=max(a[i][1],max(a[i][2],a[i][3]))){
				b1++;
				d[i]=a[i][2];
			}
			else{
				c1++;
				d[i]=a[i][3];
			}
		}
		for(int i=1;i<=n;i++){
			ans+=d[i];
		}
		if(a1==n){
			ans=0;
			sort(d+1,d+1+n);
			for(int i=1;i<=n/2;i++){
				ans+=d[i];
			}
		}
		cout<<ans;
	}
	return 0;
}
