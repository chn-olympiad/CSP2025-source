#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[3+10][100000+10];
int f[500+10][500+10][500+10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1; l<=t; l++){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		int flag=0;
		for(int i=1; i<=n; i++){
			if(a[2][i]!=0||a[3][i]!=0){
				flag=1;
			}
		}
		if(n==2){
			int maxv=0;
			for(int k=1; k<=n; k++){
				for(int i=1; i<=3; i++){
					for(int j=1; j<=3; j++){
						if(i!=j){
							maxv=max(a[i][k]+a[j][k],maxv);
							//cout<<i<<" "<<j<<" "<<maxv<<"  ";
						}
					}
				}
				//cout<<endl;
			}
			cout<<maxv<<endl;
		}else if(flag==0){
			int ans=0;
			sort(a[1]+1,a[1]+n+1);
			/*for(int i=1; i<=n; i++){
				cout<<a[1][i]<<" ";
			}*/
			//cout<<endl;
			for(int i=n; i>=n/2+1; i--){
				ans+=a[1][i];
			}
			cout<<ans<<endl;
		}else{
			int ans=0;
			for(int i=1; i<=n; i++){
				int maxv=0;
				for(int j=1; j<=3; j++){
					maxv=max(a[j][i],maxv);
					//cout<<maxv<<" ";
				}
				ans+=maxv;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
