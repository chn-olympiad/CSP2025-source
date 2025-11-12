#include<bits/stdc++.h>
using namespace std;
const int N=15,M=105;
int n,m,cur,score_of_r,num,x,y,a[N][N],f[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++)
				a[i][j]=++cur;
		}
		else{
			for(int i=n;i>=1;i--)
				a[i][j]=++cur;
		}
	}
	for(int i=1;i<=n*m;i++)
		cin>>f[i];
	score_of_r=f[1];
	sort(f+1,f+n*m+1);
	num=lower_bound(f+1,f+n*m+1,score_of_r)-f;num=n*m-num+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==num){
				cout<<j<<' '<<i;
				return 0;
			}
	return 0;
}
