#include<bits/stdc++.h>
using namespace std;
int a[100010][10]; 
int dp[100010][4];
struct num{
	int a1,a2,a3;
}e[100010];
bool cmp(num x,num y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>e[i].a1>>e[i].a2>>e[i].a3;
			}
		}
		sort(e+1,e+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=e[i].a1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
