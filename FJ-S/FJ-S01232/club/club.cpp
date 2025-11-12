#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n;
int a[N][4];
int dp1[N],dp2[N],dp3[N];
int ans=0;

int qz(int x,int y,int z) {
	int ans=x+y+z-max(x,max(y,z))-min(x,min(y,z));
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++)
				cin>>a[i][j];
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				dp1[++dp1[0]]=a[i][1]-qz(a[i][1],a[i][2],a[i][3]);
			} else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
				dp2[++dp2[0]]=a[i][2]-qz(a[i][1],a[i][2],a[i][3]);
			} else {
				dp3[++dp3[0]]=a[i][3]-qz(a[i][1],a[i][2],a[i][3]);
			}
		}
//		cout<<ans<<endl;
//²âÊÔ 
		if(dp1[0]>n/2) {
			sort(dp1+1,dp1+dp1[0]+1);
			for(int i=1; i<=dp1[0]-n/2; i++)
				ans-=dp1[i];
		} else if(dp2[0]>n/2) {
			sort(dp2+1,dp2+dp2[0]+1);
			for(int i=1; i<=dp2[0]-n/2; i++)
				ans-=dp2[i];
		} else if(dp3[0]>n/2) {
			sort(dp3+1,dp3+dp3[0]+1);
			for(int i=1; i<=dp3[0]-n/2; i++)
				ans-=dp3[i];
		}cout<<ans<<endl;
//		for(int i=1;i<=dp1[0];i++) dp1[i]=0;
//		for(int i=1;i<=dp2[0];i++) dp2[i]=0;
//		for(int i=1;i<=dp3[0];i++) dp3[i]=0;
//		for(int i=1;i<=dp1[0];i++) cout<<dp1[i]<<' ';
//		cout<<endl;
//		for(int i=1;i<=dp2[0];i++) cout<<dp2[i]<<' ';
//		cout<<endl;
//		for(int i=1;i<=dp3[0];i++) cout<<dp3[i]<<' ';
//		cout<<endl;
		dp1[0]=dp2[0]=dp3[0]=0;
		ans=0;
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
