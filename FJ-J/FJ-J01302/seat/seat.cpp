#include<bits/stdc++.h>
using namespace std;
int a[10000],ans[100][100],n,m,x,c=1,r=1,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			x++;
			if(i%2==1){
				ans[i][j]=a[n*m-x+1];
				if(j!=1)r++;
			}
			else{
				ans[i][n-j+1]=a[n*m-x+1];
				if(j!=n)r--;
			}
			if(ans[i][j]==R){
				cout<<c<<" "<<r;
				return 0;
			}
			cout<<r<<"  ";
		}
		c++;
	}
	return 0;
}
