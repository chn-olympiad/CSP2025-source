#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[10010],b[200][200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++)cin>>a[i];
	LL x=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	LL t=0;
	for(LL i=1;i<=m;i++){
		if(i%2==0){
			for(LL j=n;j>=1;j--)b[j][i]=a[++t];
		}
		else{
			for(LL j=1;j<=n;j++)b[j][i]=a[++t];
		}
	}
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
