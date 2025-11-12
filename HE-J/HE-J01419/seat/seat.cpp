#include<bits/stdc++.h>
using namespace std;
long long i,j,n,m,q=0,ans=1,sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long map[n][m],a[m*n];
	for(i=1;i<=m*n;i++)
		cin>>a[i];
	for(i=1;i<=m*n;i++)
			if(a[i]>a[1])
				ans++;
	if(ans%m!=0)q++;
	if((ans/m+q)%2==0){
		for(i=1;i<=n;i++)
			for(j=m;j>=1;j--){
				sum++;
				if(sum==ans){
					cout<<i<<' '<<j;
					return 0;
				}
			}
	}
	else
	if((ans/m+q)%2!=0){
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
			sum++;
			if(sum==ans){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
