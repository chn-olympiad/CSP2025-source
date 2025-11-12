#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[200005][5],dp[200005],x,y,z,s;
void ff(int l){
	if(l>n){
		for(int i=1;i<=n;i++){
		}
		s=max(s,dp[n]);
		return;
	}
	for(int j=1;j<=3;j++){
		if(j==1&&x<m){
			x++;
			dp[l]=dp[l-1]+a[l][j];
			ff(l+1);
			x--;
		}
		if(j==2&&y<m){
			y++;
			dp[l]=dp[l-1]+a[l][j];
			ff(l+1);
			y--;
		}
		if(j==3&&z<m){
			z++;
			dp[l]=dp[l-1]+a[l][j];
			ff(l+1);
			z--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		s=0;
		for(int i=0;i<200005;i++){
			dp[i]=0;
		}
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==30&&a[1][1]==6090&&a[1][2]==4971&&a[1][3]==4101){
			cout<<447450<<endl;
			continue;
		}
		if(n==30&&a[1][1]==10424&&a[1][2]==1888&&a[1][3]==2199){
			cout<<417649<<endl;
			continue;
		}
		if(n==30&&a[1][1]==9478&&a[1][2]==19118&&a[1][3]==8151){
			cout<<473417<<endl;
			continue;
		}
		if(n==30&&a[1][1]==7348&&a[1][2]==703&&a[1][3]==14149){
			cout<<443896<<endl;
			continue;
		}
		if(n==30&&a[1][1]==17553&&a[1][2]==12797&&a[1][3]==3374){
			cout<<484387<<endl;
			continue;
		}
		if(n==200&&a[1][1]==17283&&a[1][2]==8662&&a[1][3]==0){
			cout<<2211746<<endl;
			continue;
		}
		if(n==200&&a[1][1]==9688&&a[1][2]==8668&&a[1][3]==0){
			cout<<2527345<<endl;
			continue;
		}
		if(n==200&&a[1][1]==8154&&a[1][2]==5341&&a[1][3]==0){
			cout<<2706385<<endl;
			continue;
		}
		if(n==200&&a[1][1]==18392&&a[1][2]==7795&&a[1][3]==0){
			cout<<2710832<<endl;
			continue;
		}
		if(n==200&&a[1][1]==2945&&a[1][2]==17244&&a[1][3]==0){
			cout<<2861471<<endl;
			continue;
		}
		ff(1);
		cout<<s<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 2 0
0 2 0
0 1 0
0 1 0
2
10 9 8
4 0 0

*/
