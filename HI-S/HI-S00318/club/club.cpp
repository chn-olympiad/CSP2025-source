#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],c[4],dp[100005],sum,fl;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			sum+=a[j][3];fl=max(fl,a[j][3]);
		}
		cout<<sum-fl<<'\n';
	}
	return 0;
}
