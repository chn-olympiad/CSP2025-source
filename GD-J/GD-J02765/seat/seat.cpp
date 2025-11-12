#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
int n,m,a[MAXN][MAXN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	int cnt=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]>=a[1][1])cnt++;
//	cout<<cnt<<"\n";
	int k=0;
	while(cnt>n){
		cnt-=n;
		k++;
	}
	cout<<k+1<<" ";
	if(k&1)cout<<m-cnt+1;
	else cout<<cnt;
	return 0;
}
