#include <bits/stdc++.h>
using namespace std;
long long n,m,a[122],i,j,x,y,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+m*n+1);
	for(i=n*m;i>=1;i--)if(a[i]==x){x=n*m-i+1;break;}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(i%2==1){
				k++;
				if(j==1)k=1;
			}else{
				k--;
				if(j==1)k=n;
			}
			y++;
			if(y==x){
				cout<<i<<' '<<k;
				return 0;
			}
		}
	}
	return 0;
}
