#include<bits/stdc++.h>
using namespace std;
int q[20][20],q2[110],vis[20][20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>q2[i];
	int t = q2[1],step=1;
	sort(q2+1,q2+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++,step++)q[j][i] = q2[step];
		}
		else{
			for(int j=n;j>=1;j--,step++)q[j][i] = q2[step];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(q[i][j]==t)cout<<j<<' '<<i;
		}
	}
	return 0;
}
