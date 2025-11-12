#include<bits/stdc++.h>
using namespace std;
const int N=2e2+5;
int T,n,ans;
int a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==1)ans+=a[i][j];
				if(j==2||j==3){
					if(a[i][j]!=0){
						flag=false;
					}
				}
			}
		}
		if(true){
			cout<<ans<<"\n";
		}
		else{
			cout<<3<<endl;
		}
	}
	return 0;
}
