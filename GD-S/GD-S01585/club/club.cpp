#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][N]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long sum=0;
		long long ans=0;
		long long cnt=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(a[1][1]+a[2][2]>a[1][1]+a[2][3]){
			sum=a[1][1]+a[2][2];
		}
		else {
			sum=a[1][1]+a[2][3];
		}
		if(a[1][2]+a[2][1]>a[1][2]+a[2][3]){
			ans=a[1][2]+a[2][1];
		}
		else {
			ans=a[1][2]+a[2][3];
		}
		if(a[1][3]+a[2][1]>a[1][3]+a[2][2]){
			cnt=a[1][3]+a[2][1];
		}else {
			cnt=a[1][3]+a[2][2];
		}
		cout<<max(sum,max(ans,cnt))<<endl;
		a[i][i]={};
		a[i][i+1]={};
	}
	return 0;
}
