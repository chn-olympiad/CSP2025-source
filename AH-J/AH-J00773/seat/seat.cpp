#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m,n,aa;
LL x[105],a[15][15],cnt=1;
bool f=1;
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++){
		cin>>x[i];
	}
	aa=x[1];
	sort(x+1,x+1+n*m,cmp);
	LL j=1;
	while(cnt<n*m){
		if(f==1){
			for(LL i=1;i<=n;i++){
				a[i][j]=x[cnt++];
			}
			j++;
			f=!f;
		}
		else{
			for(LL i=n;i>=1;i--){
				a[i][j]=x[cnt++];
			}
			j++;
			f=!f;
		}
	}
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(a[i][j]==aa){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
