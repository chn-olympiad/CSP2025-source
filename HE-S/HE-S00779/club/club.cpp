//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
#include<bits/stdc++.h>
using namespace std;
struct qwe{
	int a1=0,a2=0,a3=0;//dp的是人数，a的是好感 
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		qwe a[n];
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		int dp[n]={0};
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1]+max(a[i].a1,max(a[i].a2,a[i].a3));
		}
		cout<<dp[n];
	}
	return 0;
}
