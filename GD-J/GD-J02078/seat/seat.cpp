#include<bits/stdc++.h>
using namespace std;
int mark[1000],a[100][100],n,m,mark1,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=m*n;
	for(int i=1;i<=m*n;i++)cin>>mark[i];
	mark1=mark[1],sort(mark+1,mark+m*n+1);
	for(int i=1;i<=m;i++){
		if(i%2==1)for(int j=1;j<=n;j++)a[j][i]=mark[k--];
		else   for(int j=n;j>0;j--)a[j][i]=mark[k--];
	}
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]==mark1)cout<<j<<" "<<i;
    return 0;
}
