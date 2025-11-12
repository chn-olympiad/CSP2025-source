#include<bits/stdc++.h>
using namespace std;
long long n,o;
int a[10000][10000]={0};
int vis=0,ans=0,dp[10000],Min=INT_MIN;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cin.tie(0);
	cin>>o;
	for(int t=1;t<=o;t++){
		cin>>n;
		int d=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int j=1;j<=3;j++){
			for(int i=1;i<=n;i++){
				ans+=a[i][j];
				if(a[i][j]>a[i+1][j]){
					Min=a[i][j];
				}else{
					Min=a[i+1][j];
				}
				cout<<Min<<" ";
				vis++;
				if(vis>d){
					ans-=Min;
					vis-=1;
				}
			}
			vis=0;
		}
		cout<<ans;
		ans=0;
	}
	return 0;
} 
