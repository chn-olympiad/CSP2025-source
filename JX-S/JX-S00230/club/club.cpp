#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
int a[N+10][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	while(t--){
		cin>>n;
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i+=2){
			int maxn=-111111111;
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(j==k) continue;
					maxn=max(maxn,a[i][j]+a[i+1][k]);
				}
			}
			ans1+=maxn;
		}
		for(int i=2;i<n;i+=2){
			int maxn=-111111111;
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(j==k) continue;
					maxn=max(maxn,a[i][j]+a[i+1][k]);
				}
			}
			ans2+=maxn;
		}
		int maxnn=-11111111;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(i==j) continue;
				maxnn=max(maxnn,a[1][i]+a[n][j]);
			}
		}
		ans2+=maxnn;
		cout<<max(ans1,ans2)<<"\n";
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/
