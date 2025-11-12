#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i=0,t=0;
	cin>>t;
	
	while(t--){
		cin>>i;
		int n=i;
		int a[N][n];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];		
			}
		}
		int maxn=0,d=n/2,cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>maxn&&cnt++<=d) maxn=a[i][j];
				ans+=maxn;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
