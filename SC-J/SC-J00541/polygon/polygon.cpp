#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int n,a[N],dp[N*N],top=1,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
		int tmp=top;
		for(int j=1;j<=tmp;j++){
			if(dp[j]>a[i])
			cnt++;
		}
		for(int j=1;j<=tmp;j++){
			int u=a[i]+dp[j];
			dp[++top]=u;
		}
	}
	cout<<cnt;
	return 0;
}