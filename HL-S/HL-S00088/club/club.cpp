#include <bits/stdc++.h>
using namespace std;
int a[100010][5];
int b[100010];
int c[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int m=t;
	int k=t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==1){
					b[i]=a[i][j];
					//cout<<b[i]<<endl;
				}
			}
		}
		sort(b+1,b+n+1);
		int ans=0;
		if(n%2==0){
			for(int i=n/2+1;i<=n;i++){
				ans+=b[i];
			}
		}
		else{
			for(int i=n/2+2;i<=n;i++){
				ans+=b[i];
			}
		}
		//cout<<ans;
		c[k]=ans;
		k--;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<endl;
	}
	return 0;
}
