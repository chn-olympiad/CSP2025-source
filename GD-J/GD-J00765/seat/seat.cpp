# include<bits/stdc++.h>
using namespace std;
int A[11][11],a[101],n,m,pl[101],N;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)cin>>a[i],pl[i]=a[i];
	sort(pl+1,pl+n*m+1,[&](int a,int b){return a>b;});//几行几列
	for(int i = 1;i<=m;i++){
		if(i&1)for(int j = 1;j<=n;j++)A[j][i]=pl[++N];
		else for(int j = n;j;j--)A[j][i]=pl[++N];
	}
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)if(A[i][j]==a[1])cout<<j<<" "<<i;
	return 0;
}
